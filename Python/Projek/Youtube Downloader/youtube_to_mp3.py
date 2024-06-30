import youtube_dl

url = "https://youtu.be/gNYepazLmAI?si=Ih1HO3kv6297X9N8"

ydl_opts = {
    'format': 'bestaudio/best',
    'outtmpl': '%(title)s.%(ext)s',
    'postprocessors': [{
    'key': 'FFmpegExtractAudio',
    'preferredcodec': 'mp3',
    'preferredquality': '192',
    }],
}

ydl = youtube_dl.YoutubeDL(ydl_opts)
ydl.download([url])