#version 430

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 texCoord;

layout (location = 9) uniform vec3 lightPos;
layout (location = 10) uniform vec3 lightColor;

layout (location = 17) uniform mat4 transformation;

out VS_OUT
{
    vec3 normal;
    vec2 texCoord;

    vec3 lightPos;
    vec3 lightColor;
} vs_out;

void main(void)
{
    vs_out.texCoord = texCoord;
    vs_out.normal = (transformation * vec4(normal, 0.0)).xyz;
    vs_out.lightPos = lightPos;
    vs_out.lightColor = lightColor;
    gl_Position = transformation * vec4(position, 1.0);
}

