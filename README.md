<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <title>Test Site - File Viewer</title>
    <style>
        body {
            background-color: #000;
            color: #FFF;
            font-family: Arial, sans-serif;
            margin: 0;
            padding: 0;
        }
        header {
            background-color: #333;
            padding: 10px;
            text-align: center;
        }
        h1 {
            margin: 0;
        }
        .container {
            padding: 20px;
        }
        .file-list {
            list-style: none;
            padding: 0;
        }
        .file-list li {
            margin: 5px 0;
        }
        a {
            color: #3498db;
            text-decoration: none;
        }
        .modal {
            display: none;
            position: fixed;
            z-index: 1;
            left: 0;
            top: 0;
            width: 100%;
            height: 100%;
            overflow: auto;
            background-color: rgba(0,0,0,0.7);
        }
        .modal-content {
            background-color: #333;
            margin: 15% auto;
            padding: 20px;
            border: 1px solid #888;
            width: 80%;
            color: #FFF;
        }
        .close {
            color: #FFF;
            float: right;
            font-size: 30px;
            font-weight: bold;
            cursor: pointer;
        }
    </style>
</head>
<body>
    <header>
        <h1>Test Site - File Viewer</h1>
    </header>
    <div class="container">
        <h2>Available Files:</h2>
        <ul class="file-list">
            <li>
                <a href="#" onclick="openModal('File 1.pdf', 'This is the content of File 1.pdf')">File 1.pdf</a>
            </li>
            <li>
                <a href="#" onclick="openModal('https://docs.google.com/document/d/15TvmAx8jOffFWMQK2M8_8hG7e7L8-I7M/edit?usp=share_link&ouid=108958775281637365779&rtpof=true&sd=true', 'This is the content of File 2.doc')">File 2.doc</a>
            </li>
            <li>
                <a href="#" onclick="openModal('File 3.jpg', 'This is the content of File 3.jpg')">File 3.jpg</a>
            </li>
        </ul>
    </div>

    <div id="myModal" class="modal">
        <div class="modal-content">
            <span class="close" onclick="closeModal()">&times;</span>
            <h2 id="modalFileName"></h2>
            <p id="modalFileContent"></p>
        </div>
    </div>

    <script>
        function openModal(fileName, fileContent) {
            var modal = document.getElementById("myModal");
            var modalFileName = document.getElementById("modalFileName");
            var modalFileContent = document.getElementById("modalFileContent");

            modal.style.display = "block";
            modalFileName.textContent = fileName;
            modalFileContent.textContent = fileContent;
        }

        function closeModal() {
            var modal = document.getElementById("myModal");
            modal.style.display = "none";
        }
    </script>
</body>
</html>
