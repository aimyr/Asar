# ASAR — assistive computer interface

ASAR explores accessible device control for people with severe motor impairments, combining head movement, physical inputs, and ongoing work on EEG and eye tracking. The project evolved from **UMIT Mouthpad**, a mouth-operated assistive prototype.

**Aimer Koshmambetov — CEO and project contributor | Kazakhstan | June 2024–present**

The name *asar* comes from the Kazakh tradition of collective help. The project focuses on practical access to computers and other devices, informed by work with people with disabilities and rehabilitation communities.

## Project recognition

- **ASAR — Diamond Challenge 2025: global Top 20 in social entrepreneurship.** The ASAR team became the first Kazakhstani team to reach this group of finalists. [NIS Taraz](https://trz.nis.edu.kz/en/school/nzm-taraz/news/1154)
- **UMIT Mouthpad — Red Bull Basement Kazakhstan 2024: 1st place and Tokyo World Final qualification.** Recognition for the predecessor project. [Samsung project coverage](https://csr.samsung.com/en/newsroom/news/samsung-showcases-csr-key-initiatives-to-press-in-almaty)
- **UMIT Mouthpad — Samsung Solve for Tomorrow Kazakhstan 2024: 3rd place.** Recognition for the predecessor project, listed as Umit in the official results. [Samsung results](https://solvefortomorrow.kz/ru/finalists?year=2024)

## What this repository contains

This is an archive of early prototype code, centered on head-motion and button control. It does not contain a complete EEG or eye-tracking implementation.

| File | Role |
| --- | --- |
| [send_data_from_prothesis.ino](send_data_from_prothesis.ino) | ESP32 firmware reading an MPU9250 motion sensor and buttons, and serving commands over HTTP |
| [eeprom_utils.h](eeprom_utils.h) | Sensor calibration and EEPROM helpers |
| [get_data_from_prothesis.py](get_data_from_prothesis.py) | Desktop client polling the ESP32 `/data` endpoint and translating commands into pointer movement and clicks |
| [code _to_control_wheel_chair_joystick.ino](code%20_to_control_wheel_chair_joystick.ino) | Early wheelchair joystick actuation sketch |
| `retranslator_from_esp_to_arduino(we_had_no_logic_level_shifter)` | Serial relay prototype notes/code |

The original filenames are retained to preserve references.

## Prototype architecture

```text
Head movement / buttons
        ↓
MPU9250 + ESP32
        ↓ HTTP /data
Desktop Python client
        ↓
Pointer movement and clicks
```

The wheelchair relay is a separate experimental control path. EEG and camera-based eye tracking belong to the broader project direction and are not documented here as implemented features.

## Exploring the code

The desktop client uses Python, `requests`, and `pyautogui`. It expects the ESP32 address to be configured in the script. The firmware uses Wi-Fi, a web server, an MPU9250 library, and board-specific pin assignments and calibration settings. Copy `wifi_config.h.example` to a local `wifi_config.h` and set your own network details before compiling; the local configuration file is ignored by Git.

These files require a matched hardware setup and calibration. They have not been packaged as a reproducible, clinically validated assistive product. No new hardware or user-study results are claimed by this repository.

## Public coverage

[Digital Business — project coverage, 6 May 2025](https://digitalbusiness.kz/2025-05-06/shkolniki-iz-taraza-pridumali-kak-upravlyat-invalidnoy-kolyaskoy-siloy-misli-i-popali-v-top-20-luchshih-proektov-mira/)

For current research and other projects, see [Aimer's GitHub profile](https://github.com/aimyr).
