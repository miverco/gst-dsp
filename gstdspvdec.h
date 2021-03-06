/*
 * Copyright (C) 2009 Felipe Contreras
 *
 * Author: Felipe Contreras <felipe.contreras@gmail.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation
 * version 2.1 of the License.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

#ifndef GST_DSP_VDEC_H
#define GST_DSP_VDEC_H

#include <gst/gst.h>

G_BEGIN_DECLS

#define GST_DSP_VDEC(obj) (GstDspVDec *)(obj)
#define GST_DSP_VDEC_TYPE (gst_dsp_vdec_get_type())
#define GST_DSP_VDEC_CLASS(obj) (GstDspVDecClass *)(obj)

typedef struct GstDspVDec GstDspVDec;
typedef struct GstDspVDecClass GstDspVDecClass;

#include "gstdspbase.h"

union vdec_priv_data {
	struct {
		gint lol;
	} h264;
};

struct GstDspVDec {
	GstDspBase element;
	gint width, height;
	gint frame_index;
	gboolean wmv_is_vc1;
	GstBuffer *codec_data;
	gboolean codec_data_sent;

	union vdec_priv_data priv;
};

struct GstDspVDecClass {
	GstDspBaseClass parent_class;
};

GType gst_dsp_vdec_get_type(void);

G_END_DECLS

#endif /* GST_DSP_VDEC_H */
