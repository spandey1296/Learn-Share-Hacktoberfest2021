import os

from moviepy.editor import VideoFileClip
from PIL import Image

from conf import SAMPLE_INPUTS, SAMPLE_OUTPUTS

source_path = os.path.join(SAMPLE_INPUTS, "sample.mp4")
thumbnail_dir = os.path.join(SAMPLE_OUTPUTS, "thumbnails")
thumbnail_perframe_dir = os.path.join(SAMPLE_OUTPUTS, "thumbnails_perframe")
os.makedirs(thumbnail_dir, exist_ok=True)
os.makedirs(thumbnail_perframe_dir, exist_ok=True)

clip = VideoFileClip(source_path)
# print(clip.reader.fps)      # frames per second
# print(clip.reader.nframes)         # total frames
# print(clip.duration)        # seconds

fps = clip.reader.fps
nframes = clip.reader.nframes
seconds = nframes / (fps*1.0)

duration = clip.duration
max_duration = int(duration)+1
for i in range(0, max_duration):
    frame = clip.get_frame(int(i))
    new_img_path = os.path.join(thumbnail_dir, f"{i}.jpg")
    # print(f"frame at {i} seconds saved at {new_img_path}")
    new_img = Image.fromarray(frame)
    new_img.save(new_img_path)
    # print(frame)


for i, frame in enumerate(clip.iter_frames()):
    # print(frame) # np.array numpy array # inference
    if i % fps == 0:
        current_ms = int((i / fps) * 1000)
        new_img_filepath = os.path.join(
            thumbnail_perframe_dir, f"{current_ms}.jpg")
        # print(f"frame at {i} seconds saved at {new_img_filepath}")
        new_img = Image.fromarray(frame)
        new_img.save(new_img_filepath)
