#ifndef EXIFUTIL_H
#define EXIFUTIL_H

#include <libexif/exif-data.h>
#include <libexif/exif-entry.h>
#include <libexif/exif-tag.h>
#include <QMap>
#include <QDebug>

static void parse_tag(ExifData *d, ExifIfd ifd, ExifTag tag);
static void show_mnote_tag(ExifData *d, unsigned tag);
static QMap<QString, QString> imgInfoMap;
QMap<QString, QString> exif_image_url(const QString &imageUrl);
#endif // EXIFUTIL_H
