#version 330 core
uniform vec2 u_resolution;
out vec4 FragColor;

void main() {
    vec2 uv = gl_FragCoord.xy / u_resolution;
    float checker = mod(floor(uv.x * 10.0) + floor(uv.y * 10.0), 2.0);
    FragColor = vec4(vec3(checker), 1.0);
}
