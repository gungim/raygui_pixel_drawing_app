#include "import_file.hpp"
#include "context.hpp"
#include "cstring"
#include "raygui.h"

#include <math.h> // Required for: round()
#include <stdio.h>
#include <stdlib.h> // Required for: atoi()
//
namespace app {

    ImportFile::ImportFile() {
        std::strcpy(this->fileName, "\0");
        std::strcpy(this->fileNamePath, "\0");
        this->dataSize = 0;

        this->headerSizeValue = 0;
        this->bitDepthActive = 0;
        this->channelsActive = 3;
        this->pixelFormatActive = 0;
        this->heightValue = 0;
        this->widthValue = 0;

        this->widthEditMode = false;
        this->heightEditMode = false;
        this->headerSizeEditMode = false;

        this->open = false;
        this->btnLoadPressed = false;

        int screenWidth = GetScreenWidth();
        int screenHeight = GetScreenHeight();

        this->offset = {(float)(screenWidth - 200) / 2,
                        (float)(screenHeight - 465) / 2};
    }
    ImportFile::~ImportFile() {}

    void ImportFile::Draw(Context context) {

        if (this->open) {
            this->open = !GuiWindowBox(
                (Rectangle){this->offset.x + 0, this->offset.y + 0, 200, 465},
                "Image RAW Import Options");

            GuiLabel(
                (Rectangle){this->offset.x + 10, this->offset.y + 30, 65, 20},
                "Import file:");
            GuiLabel(
                (Rectangle){this->offset.x + 85, this->offset.y + 30, 75, 20},
                fileName);
            GuiLabel(
                (Rectangle){this->offset.x + 10, this->offset.y + 50, 65, 20},
                "File size:");
            GuiLabel(
                (Rectangle){this->offset.x + 85, this->offset.y + 50, 75, 20},
                TextFormat("%i bytes", dataSize));
            GuiGroupBox(
                (Rectangle){this->offset.x + 10, this->offset.y + 85, 180, 80},
                "Resolution");
            GuiLabel(
                (Rectangle){this->offset.x + 20, this->offset.y + 100, 33, 25},
                "Width:");
            if (GuiValueBox((Rectangle){this->offset.x + 60,
                                        this->offset.y + 100, 80, 25},
                            NULL, &this->widthValue, 0, 8192,
                            this->widthEditMode))
                this->widthEditMode = !this->widthEditMode;
            GuiLabel(
                (Rectangle){this->offset.x + 145, this->offset.y + 100, 30, 25},
                "pixels");
            GuiLabel(
                (Rectangle){this->offset.x + 20, this->offset.y + 130, 33, 25},
                "Height:");
            if (GuiValueBox((Rectangle){this->offset.x + 60,
                                        this->offset.y + 130, 80, 25},
                            NULL, &this->heightValue, 0, 8192,
                            this->heightEditMode))
                this->heightEditMode = !this->heightEditMode;
            GuiLabel(
                (Rectangle){this->offset.x + 25, this->offset.y + 370, 27, 25},
                "Size:");
            if (GuiValueBox((Rectangle){this->offset.x + 55,
                                        this->offset.y + 370, 85, 25},
                            NULL, &this->headerSizeValue, 0, 10000,
                            this->headerSizeEditMode))
                this->headerSizeEditMode = !this->headerSizeEditMode;
            GuiLabel(
                (Rectangle){this->offset.x + 145, this->offset.y + 370, 30, 25},
                "bytes");
            btnLoadPressed = GuiButton(
                (Rectangle){this->offset.x + 10, this->offset.y + 420, 180, 30},
                "Import RAW");
        }

        if (IsFileDropped()) {
            FilePathList droppedFiles = LoadDroppedFiles();

            // Check file extensions for drag-and-drop
            if ((droppedFiles.count == 1) &&
                IsFileExtension(droppedFiles.paths[0], ".png")) {
                FILE* imageFile = fopen(droppedFiles.paths[0], "rb");
                fseek(imageFile, 0L, SEEK_END);
                dataSize = ftell(imageFile);
                fclose(imageFile);

                // NOTE: Returned string is just a pointer to droppedFiles[0],
                // we need to make a copy of that data somewhere else: fileName
                strcpy(this->fileNamePath, droppedFiles.paths[0]);
                strcpy(this->fileName, GetFileName(droppedFiles.paths[0]));

                // Try to guess possible raw values
                // Let's assume image is square, RGBA, 8 bit per channel
                this->widthValue = round(sqrt(dataSize / 4));
                this->heightValue = this->widthValue;
                this->headerSizeValue =
                    dataSize - this->widthValue * heightValue * 4;
                if (this->headerSizeValue < 0)
                    this->headerSizeValue = 0;

                this->open = true;
            }

            UnloadDroppedFiles(droppedFiles);
        }

        if (btnLoadPressed) {
            // Depending on channels and bit depth, select correct pixel format
            if ((this->widthValue != 0) && (this->heightValue != 0)) {
                int format = -1;

                if (pixelFormatActive == 0) {
                    int channels =
                        atoi(context.channelsTextList[channelsActive]);
                    int bpp = atoi(context.bitDepthTextList[bitDepthActive]);

                    // Select correct format depending on channels and bpp
                    if (bpp == 8) {
                        switch (channels) {
                        case 1:
                            format = PIXELFORMAT_UNCOMPRESSED_GRAYSCALE;
                            break;
                        case 2:
                            format = PIXELFORMAT_UNCOMPRESSED_GRAY_ALPHA;
                            break;
                        case 3:
                            format = PIXELFORMAT_UNCOMPRESSED_R8G8B8;
                            break;
                        case 4:
                            format = PIXELFORMAT_UNCOMPRESSED_R8G8B8A8;
                            break;
                        }
                    } else if (bpp == 32) {
                        if (channels == 1)
                            format = PIXELFORMAT_UNCOMPRESSED_R32;
                        else if (channels == 2)
                            TraceLog(LOG_WARNING,
                                     "Channel bit-depth not supported!");
                        else if (channels == 3)
                            format = PIXELFORMAT_UNCOMPRESSED_R32G32B32;
                        else if (channels == 4)
                            format = PIXELFORMAT_UNCOMPRESSED_R32G32B32A32;
                    } else if (bpp == 16)
                        TraceLog(LOG_WARNING,
                                 "Channel bit-depth not supported!");
                } else
                    format = pixelFormatActive;

                if (format != -1) {
                    Image image = LoadImage(fileNamePath);
                    Texture2D texture = LoadTextureFromImage(image);
                    char* locale;
                    std::strcpy(locale, "\0");
				// add project
                    open = false;
                    btnLoadPressed = false;
                }
            }
        }
    }
} // namespace app
