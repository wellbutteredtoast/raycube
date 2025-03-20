#version 330

uniform sampler2D texture0;
uniform float pixelSize;
in vec2 fragTexCoord;
out vec4 finalColor;

void main() {
    vec2 resolution = textureSize(texture0, 0);
    vec2 uv = fragTexCoord;
    
    uv = floor(uv * resolution / pixelSize) * pixelSize / resolution;
    finalColor = texture(texture0, uv);
}
