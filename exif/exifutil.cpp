#include "exifutil.h"

static void parse_tag(ExifData *d, ExifIfd ifd, ExifTag tag) {
    ExifEntry *entry = exif_content_get_entry(d->ifd[ifd], tag);
    if (entry) {
        char buf[1024];
        /* Get the contents of the tag in human-readable form */
        exif_entry_get_value(entry, buf, sizeof(buf));

        if (*buf) {
            qDebug() << "exif info:" << exif_tag_get_name_in_ifd(tag, ifd);
        }
    }
}

static void show_mnote_tag(ExifData *d, unsigned tag) {
    ExifMnoteData *mn = exif_data_get_mnote_data(d);
    if (mn) {
        int num = exif_mnote_data_count(mn);

        for(int i = 0; i < num; i++) {
            char buf[1024];
            if (exif_mnote_data_get_value(mn, i, buf, sizeof(buf))) {
                if (*buf) {
                    qDebug() << "exif mnote data get title"
                             << exif_mnote_data_get_title(mn, i)
                             << buf;
                }
            }
        }
    }
}

QMap<QString, QString> *exif_image_url(const QString &imageUrl) {
    ExifData* ed;

//    ExifEntry* entry;
    ed = exif_data_new_from_file(imageUrl.toUtf8().data());
    qDebug() << "ed:" << ed;
    if (!ed) {
        return NULL;
    }

    parse_tag(ed, EXIF_IFD_0, EXIF_TAG_DATE_TIME);
    parse_tag(ed, EXIF_IFD_0, EXIF_TAG_DATE_TIME_DIGITIZED);
    parse_tag(ed, EXIF_IFD_0, EXIF_TAG_ARTIST);
    parse_tag(ed, EXIF_IFD_0, EXIF_TAG_COPYRIGHT);
    // EXIF_TAG_PADDING:
    qDebug() << "EXIF_TAG_PADDING";
    // EXIF_TAG_PADDDING;
//    parse_tag(ed, EXIF_IFD_COUNT, EXIF_TAG_PADDING << 2);
//    parse_tag(ed, EXIF_IFD_COUNT, EXIF_TAG_PADDING << 3);

//    parse_tag(ed, EXIF_IFD_COUNT, EXIF_TAG_PADDING << 4);
//    parse_tag(ed, EXIF_IFD_COUNT, EXIF_TAG_PADDING << 5);
//    parse_tag(ed, EXIF_IFD_COUNT, EXIF_TAG_PADDING << 6);

    parse_tag(ed, EXIF_IFD_EXIF, EXIF_TAG_COLOR_SPACE);
    parse_tag(ed, EXIF_IFD_EXIF, EXIF_TAG_EXPOSURE_MODE);
    parse_tag(ed, EXIF_IFD_EXIF, EXIF_TAG_EXPOSURE_PROGRAM);
    parse_tag(ed, EXIF_IFD_EXIF, EXIF_TAG_EXPOSURE_TIME);
    parse_tag(ed, EXIF_IFD_EXIF, EXIF_TAG_FLASH);
    parse_tag(ed, EXIF_IFD_EXIF, EXIF_TAG_APERTURE_VALUE);
    parse_tag(ed, EXIF_IFD_EXIF, EXIF_TAG_FOCAL_LENGTH);

}
