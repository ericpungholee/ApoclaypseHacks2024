from flask import Blueprint, current_app, jsonify, render_template, request
from flask_login import login_required

from apocalift.main.utils import (
    SERVO_LEFT_BOUND,
    SERVO_MID,
    SERVO_RIGHT_BOUND,
    SPEED_PERCENTAGE,
    init_arduino,
    write_read,
)


main = Blueprint("main", __name__)


@main.route("/")
@main.route("/home")
def home():
    return render_template("home.html", title="Home")


@main.route("/about")
def about():
    return render_template("about.html", title="About")


@main.route("/test_control")
@login_required
def test_control():
    coordinate = (43.64485589208203, -79.4007881899902)
    latitude, longitude = coordinate
    return render_template(
        "test_control.html",
        title="Control",
        power="100%",
        coordinate=coordinate,
        latitude=latitude,
        longitude=longitude,
        video_feed_url=current_app.config["VIDEO_FEED_URL"],
    )


@main.route("/receive_keypress", methods=["POST"])
def receive_keypress():
    payload = request.get_json(silent=True) or {}
    keys = set(payload.get("value", []))
    moving_forward = "w" in keys
    turning_left = "a" in keys
    turning_right = "d" in keys

    speed = SPEED_PERCENTAGE if moving_forward else "00"
    angle = SERVO_MID
    if turning_left ^ turning_right:
        angle = SERVO_LEFT_BOUND if turning_left else SERVO_RIGHT_BOUND

    command = f"{speed}{angle}"
    arduino = None
    try:
        arduino = init_arduino(
            current_app.config["ARDUINO_PORT"],
            current_app.config["ARDUINO_BAUDRATE"],
        )
        write_read(command, arduino)
    except Exception:
        current_app.logger.exception("Failed to send control command")
    finally:
        if arduino is not None and arduino.is_open:
            arduino.close()

    return jsonify(command=command)
