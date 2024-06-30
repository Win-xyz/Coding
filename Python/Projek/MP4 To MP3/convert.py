import subprocess

mp4 = "jeje.mp4"
mp3 = "jeje.mp3"

subprocess.call(["ffmpeg", "-i", mp4, mp3])
print("Konversi selesai...")