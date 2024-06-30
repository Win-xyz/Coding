from gtts import gTTS

text = "jawa adalah kunci. jawa itu kuat. hidup jawirrr"
language = "id"

text_to_speech = gTTS(text = text, lang = language)

file_name = "audio.mp3"
text_to_speech.save(file_name)
print(f"{file_name} berhasil tersimpan...")