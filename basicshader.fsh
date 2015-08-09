#version 430

layout (binding = 0) uniform sampler2D tex;

in VS_OUT
{
    vec3 normal;
    vec2 texCoord;

    vec3 lightPos;
    vec3 lightColor;
} fs_in;

out vec4 color;

void main()
{
    //color = vec4(0.0, 1.0, 0.0, 1.0);
    vec3 lightPos = normalize(vec3(1.0, 1.0, 1.0));
    vec3 normal = normalize(fs_in.normal);
    //color = texture(tex, fs_in.texCoord) * clamp(dot(normal, -lightPos), 0.0, 1.0);
    color = vec4(0.1, 0.7, 0.4, 1.0) * clamp(dot(normal, -lightPos), 0.0, 1.0);
    //color = clamp(vec4(fs_in.normal, 1.0), vec4(0.0, 0.0, 0.0, 0.0), vec4(1.0, 1.0, 1.0, 1.0));
}
