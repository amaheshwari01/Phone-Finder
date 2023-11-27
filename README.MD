# Phone-Finder
This is a Project that uses an ESP32 based Microcontroller(the [TINYPICO](https://www.tinypico.com/)) as an IOT button to find my Phone!!!

## How It Works
- Press Reset Button on Tiny-Pico to ping phone
    - Light will be red while trying to connect
    - Yellow While Sending request
    - Blue if Request failed and it is retrying
    - Green When Succesful
- If Reset Button is pressed in between before device is pinged, the process will be terminated



## How To Get Started and Run this project

### Server SETUP 
this project uses poetry to install look [here](https://python-poetry.org/docs/)

- Clone The Repo
- cd into the ping_server folder
- run `poetry init` to get started
- create a copy of `keys_example.py` and call it `keys.py`
- Fill out icloud credintials and API-KEY(can be anything)
- run ping.py by running `poetry run python3 keys.py`
- Fill out all required auth and find the Device ID corresponding to the device you want 
- Paste Device ID into keys.py 
- Run Server `poetry run python3 main.py` (will run on port 1200)
- EXTRA: if you would like it to work on other networks you can setup a cloudflare tunnel

### Arduino SETUP
- Install the libraries and make sure ESP32 is Setup with arduino IDE([instructions](https://randomnerdtutorials.com/installing-the-esp32-board-in-arduino-ide-windows-instructions/))
- Edit Lines `33-34` with your wifi Network Details
- Edit Lines `57-58` with server URL and API Key
- UPLOAD!!
- I would recomend attaching a 1S LIPO Battery to the Tiny-Pico to make it portable 
 




