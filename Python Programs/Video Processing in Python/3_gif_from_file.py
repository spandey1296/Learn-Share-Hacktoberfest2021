import os

from moviepy.editor import *
from moviepy.video.fx.all import crop
from PIL import Image
from sympy import im

from conf import SAMPLE_INPUTS, SAMPLE_OUTPUTS

GIF_DIR = os.path.join(SAMPLE_OUTPUTS, "gifs")
os.makedirs(GIF_DIR, exist_ok=True)
output_1 = os.path.join(GIF_DIR, "sample1.gif")
output_2 = os.path.join(GIF_DIR, "sample2.gif")
source_path = os.path.join(SAMPLE_INPUTS, "sample.mp4")
clip = VideoFileClip(source_path)
fps = clip.reader.fps
subclip = clip.subclip(10, 20)
sunclip = subclip.resize(width=320)
# subclip.write_gif(output_1, fps=20)
# subclip.write_gif(output_1, fps=20, program='ffmpeg')


w, h = clip.size
subclip2 = clip.subclip(10, 20)
cropped_clip = crop(subclip2, width=320, height=320,
                    x_center=w/2, y_center=h/2)
subclip2.write_gif(output_2, fps=fps, program='ffmpeg')
