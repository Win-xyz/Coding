import youtube_dl

url = "https://youtu.be/gNYepazLmAI?si=Ih1HO3kv6297X9N8" 

ydl = youtube_dl.YoutubeDL()
ydl.download([url])