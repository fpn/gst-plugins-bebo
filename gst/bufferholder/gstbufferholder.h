/*
 * GStreamer
 * Copyright (C) 2015 Matthew Waters <matthew@centricular.com>
 * Copyright (C) 2018 Pigs in Flight, Inc
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin St, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#ifndef __GST_BUFFER_HOLDER__
#define __GST_BUFFER_HOLDER__

#include <gst/video/video.h>

G_BEGIN_DECLS

#define GST_TYPE_BUFFER_HOLDER (gst_buffer_holder_get_type())
#define GST_BUFFER_HOLDER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), GST_TYPE_BUFFER_HOLDER, GstBufferHolderClass))
#define GST_BUFFER_HOLDER(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj),GST_TYPE_BUFFER_HOLDER,GstBufferHolder))
#define GST_BUFFER_HOLDER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST((klass),GST_TYPE_BUFFER_HOLDER, GstBufferHolderClass))
#define GST_IS_BUFFER_HOLDER(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj),GST_TYPE_BUFFER_HOLDER))
#define GST_IS_BUFFER_HOLDER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE((klass),GST_TYPE_BUFFER_HOLDER))
#define GST_BUFFER_HOLDER_CAST(obj) ((GstBufferHolder*)(obj))

typedef struct _GstBufferHolder GstBufferHolder;
typedef struct _GstBufferHolderClass GstBufferHolderClass;
typedef struct _GstBufferHolderPrivate GstBufferHolderPrivate;

/**
 * GstBufferHolder
 *
 * Opaque #GstBufferHolder object
 */
struct _GstBufferHolder
{
  /* <private> */
  GstBaseTransform parent;
  GAsyncQueue   *queue;
  guint64 size_buffers;
};

/**
 * GstBufferHolderClass:
 *
 * The #GstBufferHolderClass struct only contains private data
 */
struct _GstBufferHolderClass
{
  GstGLBaseFilterClass object_class;
  gboolean(*set_caps)          (GstBufferHolder* gl2dxgi, GstCaps* incaps, GstCaps* outcaps);
};

G_END_DECLS

GType gst_buffer_holder_get_type (void);

#endif /* __GST_GL_2_DXGI_H__ */
