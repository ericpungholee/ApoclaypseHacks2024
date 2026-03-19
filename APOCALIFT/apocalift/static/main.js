const pressedKeys = new Set();
const controlKeys = new Set(["w", "a", "d"]);
const pollIntervalMs = 100;

function updatePressedKeys(event) {
    const key = event.key.toLowerCase();
    if (!controlKeys.has(key)) {
        return;
    }

    if (event.type === "keydown") {
        pressedKeys.add(key);
    } else {
        pressedKeys.delete(key);
    }
}

async function sendPressedKeys() {
    try {
        await fetch("/receive_keypress", {
            method: "POST",
            headers: {
                "Content-Type": "application/json",
            },
            body: JSON.stringify({ value: [...pressedKeys] }),
        });
    } catch (error) {
        console.error(error);
    }
}

document.addEventListener("keydown", updatePressedKeys);
document.addEventListener("keyup", updatePressedKeys);
setInterval(sendPressedKeys, pollIntervalMs);


