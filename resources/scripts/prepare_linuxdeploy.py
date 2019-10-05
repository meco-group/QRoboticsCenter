import os

ROOT = "build/app/"
os.makedirs(ROOT + "usr/lib/", exist_ok=True)
os.makedirs(ROOT + "usr/bin/", exist_ok=True)
os.makedirs(ROOT + "usr/share/applications/", exist_ok=True)
os.makedirs(ROOT + "usr/share/icons/hicolor/256x256/", exist_ok=True)

content = [
    "[Desktop Entry]",
    "Type=Application",
    "Name=QRoboticsCenter",
    "Comment=Interfacing Embedded Development",
    "Exec=QRoboticsCenter",
    "Icon=QRoboticsCenter",
    "Categories=Office;"
]

file = open(ROOT + "usr/share/applications/QRoboticsCenter.desktop", "w")
for l in content:
    file.write(l + "\n")
file.close()
