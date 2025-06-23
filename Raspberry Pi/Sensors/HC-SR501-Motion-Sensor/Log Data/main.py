import time
import sys
from datetime import datetime
from gpiozero import MotionSensor
from signal import pause

PIR_GPIO_PIN = 17

motion_count = 0
last_motion_time = None

def log(msg):
    timestamp = datetime.now().strftime("[%Y-%m-%d %H:%M:%S]")
    print(f"{timestamp} {msg}")

try:
    log("Initializing PIR sensor...")

    pir = MotionSensor(PIR_GPIO_PIN)

    log(f"Using PIR sensor on GPIO {PIR_GPIO_PIN}")
    log("Waiting for PIR sensor to settle (up to 10s)...")
    pir.wait_for_no_motion(timeout=10)

    log("PIR sensor ready. Waiting for motion...")

    def on_motion():
        global motion_count, last_motion_time
        now = datetime.now()

        if last_motion_time:
            delta = (now - last_motion_time).total_seconds()
            log(f"Time since last motion: {delta:.2f} seconds")
        last_motion_time = now

        motion_count += 1
        log(f"Motion #{motion_count} detected!")

        time.sleep(1)  # debounce

    def on_no_motion():
        log("No more motion.")

    pir.when_motion = on_motion
    pir.when_no_motion = on_no_motion

    pause()

except KeyboardInterrupt:
    log("Exiting program (KeyboardInterrupt).")
    sys.exit(0)

except Exception as e:
    log(f"Error: {e}")
    sys.exit(1)
