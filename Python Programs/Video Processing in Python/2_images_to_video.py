import os

from moviepy.editor import ImageClip, ImageSequenceClip
from PIL import Image

from conf import SAMPLE_INPUTS, SAMPLE_OUTPUTS

thumbnail_dir = os.path.join(SAMPLE_OUTPUTS, "thumbnails")
thumbnail_perframe_dir = os.path.join(SAMPLE_OUTPUTS, "thumbnails_perframe")
output_video = os.path.join(SAMPLE_OUTPUTS, "thumbs.mp4")
os.makedirs(thumbnail_dir, exist_ok=True)
os.makedirs(thumbnail_perframe_dir, exist_ok=True)

# this_dir = os.listdir(thumbnail_dir)
# filepaths = [os.path.join(thumbnail_dir, fname)
#              for fname in this_dir if fname.endswith('jpg')]

# clip = ImageSequenceClip(filepaths, fps=1)
# clip.write_videofile(output_video)

# fix Ordering
directory = {}

for root, dirs, files in os.walk(thumbnail_perframe_dir):
    for fname in files:
        filepath = os.path.join(root, fname)
        try:
            key = float(fname.replace(".jpg", ""))
        except:
            key = None
        if key is not None:
            directory[key] = filepath

new_paths = []
for k in sorted(directory.keys()):
    # print(k)
    new_paths.append(directory[k])

# clip = ImageSequenceClip(new_paths, fps=1)
# clip.write_videofile(output_video)

my_clips = []
for path in new_paths:
    frame = ImageClip(path)
    my_clips.append(frame.img)

clip = ImageSequenceClip(my_clips, fps=4)
clip.write_videofile(output_video)
