/**
 * File name: export_widget.h
 * Project: Geonkick (A kick synthesizer)
 *
 * Copyright (C) 2018 Iurie Nistor (http://geontime.com)
 *
 * This file is part of Geonkick.
 *
 * GeonKick is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#ifndef GEONKICK_EXPORT_WIDGET_H
#define GEONKICK_EXPORT_WIDGET_H

#include "geonkick_widget.h"

class GeonkickApi;
class RkLineEdit;
class RkLabel;
class RkProgressBar;

class ExportWidget: public GeonkickWidget {
 public:
        ExportWidget(GeonkickWidget *parent, GeonkickApi *api);
        ~ExportWidget();

 protected:
        void createFormatButtons();
        void setFormat(ExportFormat format);
        void createChannelsButtons();
        void setChannels(ChannlesType channels);
        int exportFormat();
        void enableButtons(bool enable);
        std::string getFilePath();
        std::string fileSuffix();
        bool validateInput();

        void browse();
        void cancel();
        void exportKick();
        void resetProgressBar();
        void showError(const std::string &error = std::string());

 private:
        enum class ChannelsType: int {
                Mono,
                Stereo
        };
        
         enum class ExportFormat: int {
                 Flac16 = 0,
                 Flac24 = 1,
                 Wav16  = 2,
                 Wav24  = 3,
                 Wav32  = 4,
                 Ogg    = 5
         };

        GeonkickApi *geonkickApi;
        ExportResult exportResult;
        RkLineEdit *locationEdit;
        RkLineEdit *fileNameEdit;
        GeonkickButton *browseLocation;
        GeonkickButton *flac16Button;
        GeonkickButton *flac242Button;
        GeonkickButton *wav16Button;
        GeonkickButton *wav242Button;
        GeonkickButton *wav32Button;
        GeonkickButton *oggButton;
        GeonkickButton *monoButton;
        GeonkickButton *stereoButton;
        RkProgressBar  *progressBar;
        GeonkickButton *exportButton;
        GeonkickButton *cancelButton;
        RkLabel *errorLabel;
        ExportFormat selectedFormat;
        ChannelsType channlesType;
};

#endif // GEONKICK_EXPORT_WIDGET_H
