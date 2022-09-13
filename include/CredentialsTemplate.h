/*******************************************************************
 * IMPORTANT! Please follow the instructions in this file before
 * you try to compile the project for the first time. This file
 * is just a template, don't change the contents of this file.
 * 
 * You need to do the following:
 * 1. Save this file as Credentials.h in include/ directory and
 *    than close this file
 * 2. Open Credentials.h file and enter your WiFi credentials and
 *    device Id from remlog server (see remlog documentation). 
 *    Add server IP address, it should be your local network address,
 *    e.g. "192.168.0.101", don't add anything else to the string. 
 *    By default, remlog listenes on port 8888, if you've 
 *    configured it differently, change this value too
 * 3. Save this file and compile and upload the project to ESP32
 *    board
 * 
 * Credentials.h is ignored by Git (check the contents of .gitignore
 * file to confirm), so this way your credentials will be kept in
 * your local version of the project. This way you can change the 
 * project and publish your changes on Github, Gitlab, Bitbucket or
 * your own Git server without leaking sensitive information.
 * Once you're done, you can delete this comment block from
 * Credentials.h file.
 *******************************************************************/

#ifndef CREDENTIALS_H
    #define CREDENTIALS_H
    // Add your WiFI credentials
    #define WIFI_SSID "Your SSID"
    #define WIFI_PASSWORD "Your password"
    // Add device Id
    #define DEVICE_ID "Remlog device id"
    // Add remlog server data
    #define REMLOG_IP_ADDRESS "192.168.0.0"
    #define REMLOG_PORT "8888" // this is default value, change if needed
#endif