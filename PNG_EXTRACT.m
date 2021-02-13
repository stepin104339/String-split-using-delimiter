clear all;
clc;
text = fileread('LTTS.html');
Lines = strsplit(text,newline);
d=1;

for i=1:length(Lines)
    if contains(Lines{i},"<img")
        newStr = extractBetween(Lines{i},"<img",">");
        for j=1:length(newStr)
            ValueStorage{d}=newStr{j};
            d=d+1;
        end
    end
end 
fprintf("number of images in this website is %d",d)
ValueStorage=vertcat("images VALUE",ValueStorage');
ValueStorage_XLS= cellstr(ValueStorage);
xlswrite("LTTS.xlsx",ValueStorage_XLS);

