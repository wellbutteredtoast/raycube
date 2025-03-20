#version 330 core
uniform float u_time;
out vec4 FragColor;

void main() {
    float r = sin(u_time) * 0.5 + 0.5;
    float g = cos(u_time) * 0.5 + 0.5;
    float b = sin(u_time * 0.5) * 0.5 + 0.5;
    FragColor = vec4(r, g, b, 1.0);
}
