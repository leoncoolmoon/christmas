static const char PROGMEM INDEX_HTML[] = R"rawliteral(
<!doctype html>
<html>

<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width,initial-scale=1, user-scalable=no">
    <title>Christmas light house setting</title>
    <style>
  </style>
</head>
<body>
</br>
Christmas light house setting
</br>
<button class="button" onclick="fetch(document.location.origin+'/cmd/LED1');">LED1 on/off</button></br>
<button class="button" onclick="fetch(document.location.origin+'/cmd/LED2');">LED2 on/off</button></br>
<button class="button" onclick="fetch(document.location.origin+'/cmd/TRAIN');">TRAIN run/stop</button></br>
<button class="button" onclick="fetch(document.location.origin+'/cmd/MUSIC');">MUSIC on/off</button></br>
<button class="button" onclick="fetch(document.location.origin+'/cmd/VP');">Volume +</button></br>
<button class="button" onclick="fetch(document.location.origin+'/cmd/VM');">Volume -</button></br>
Change Music (MP3 <64Kbps <512kb):
<form method='POST' action='/upload' enctype='multipart/form-data'><input type='file' name='upload'></br><input type='submit' value='Upload Music'></form>
<button class="button" onclick="fetch(document.location.origin+'/cmd/music.mp3');">Download Music</button></br>
<button class="button" onclick="fetch(document.location.origin+'/cmd/RST');">Reset Music</button></br>
      <script>
      </script>
</body>

</html>
)rawliteral";
