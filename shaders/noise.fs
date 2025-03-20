#version 330 core
out vec4 FragColor;

float random(vec2 uv) {
    return fract(sin(dot(uv, vec2(12.9898, 78.233))) * 43758.5453123);
}

void main() {
    vec2 uv = gl_FragCoord.xy / vec2(800, 600); // Replace with resolution
    float noise = random(uv);
    FragColor = vec4(vec3(noise), 1.0);
}
