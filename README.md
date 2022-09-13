# remlog-client
Simple client example for [remlog](https://github.com/mikrotron-zg/remlog) project, using [ESP32 Devkit board](https://www.diykits.eu/shophr/products/wireless/p_11638).

### Instructions
Open in Visual Studio Code (with PlatformIO plugin installed), open _CredentialsTemplate.h_ file and follow instructions. Then build and upload to the device. Please note that the first build could take longer to finish as it will download all the components needed to compile. If build falils, try restarting Visual Studio Code, then start the build again. Some ESP32 boards (including the one we youse for this project) require that you press the 'boot' button after you initiate upload to the device, otherwise the upload will fail.
