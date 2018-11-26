clear;
clc;

% pixel_freq_file = 'F:\Users\cse\Desktop\new\pixel_frequency.txt';
% output_img = 'F:\Users\cse\Desktop\new\output.bmp';
% gray_img = 'F:\Users\cse\Desktop\new\gray.bmp';

pixel_freq_file = 'pixel_frequency.txt';
output_img = 'output.bmp';
gray_img = 'gray.bmp';

img = imread('u2.bmp');
%img = rgb2gray(img);
imwrite(img, gray_img);
figure, imshow(img);

[r, c] = size(img);

fileID = fopen(pixel_freq_file, 'w');

for i = 1:r
    x = 0;                  % Frequency of Pixel
    y = -1;                 % Pixel Value
    for j = 1:c
        if j == 1
            y = img(i, j);
            x = 0;
        end
        if(y == img(i, j) )
            x = x + 1;
        end
        if(y ~= img(i, j))
            
            if(y ~= -1)
                
                spec = '%d %d ';
                fprintf(fileID, '%d %d\n', y, x);
            end
            y = img(i, j);
            x = 1;
        end
        if j == c
            spec = '%d %d ';
            fprintf(fileID, '%d %d\n', y, x);
        end
        
    end
end
fclose(fileID);
            
                
fileID = fopen(pixel_freq_file, 'r');
formatSpec = '%d %d';

rex = fscanf(fileID, formatSpec);
fclose(fileID);

nimg = zeros(r, c);
k = 1;
p = 0;
i = 1;
while i <= r
   j = 1;
   while j <= c
        nimg(i, j:j+rex(k+1)-1) = rex(k);
        j = j + rex(k+1)
        k = k + 2;
   end
   i = i + 1;
end
nimg = uint8(nimg);
figure, imshow(nimg);
imwrite(nimg, output_img);
