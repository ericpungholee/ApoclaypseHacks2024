import os


class Config:
    SECRET_KEY = os.getenv("SECRET_KEY", "dev-secret-key")
    SQLALCHEMY_DATABASE_URI = os.getenv("DATABASE_URL", "sqlite:///site.db")
    SQLALCHEMY_TRACK_MODIFICATIONS = False
    ARDUINO_PORT = os.getenv("ARDUINO_PORT", "COM19")
    ARDUINO_BAUDRATE = int(os.getenv("ARDUINO_BAUDRATE", "115200"))
    VIDEO_FEED_URL = os.getenv("VIDEO_FEED_URL", "http://10.93.92.140:5000/")
