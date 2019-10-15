#version 330 core

out vec4 FragColor;

struct Material {
	sampler2D diffuse;
	sampler2D specular;
	float shininess;
};

struct Light {
    vec3 position;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

in vec3 FragPos;
in vec3 Normal;
in vec2 TexCoords;

//in vec2 TexCoord;
// texture samplers
//uniform sampler2D texture1;
//uniform sampler2D texture2;

uniform vec3 viewPos;
uniform Material material;
uniform Light light;


void main()
{
	//calculate ambient lighting
	vec3 ambient = light.ambient * vec3(texture(material.diffuse, TexCoords));
	// linearly interpolate between both textures (80% container, 20% awesomeface)
	//vec4 result = mix(texture(texture1, TexCoord), texture(texture2, vec2(TexCoord.x, TexCoord.y)), 0.2) * vec4(ambient,1.0);
	

	//calculate diffuse ligthing
	vec3 norm = normalize(Normal);
	vec3 lightDir = normalize(light.position - FragPos);
	float diff = max(dot(norm, lightDir), 0.0);
	vec3 diffuse = light.diffuse * diff * vec3(texture(material.diffuse, TexCoords));

	//calulate specular lighting	
	vec3 viewDir = normalize(viewPos - FragPos);
	vec3 reflectDir = reflect(-lightDir, norm);
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
	vec3 specular = light.specular * spec * vec3(texture(material.specular, TexCoords));  


	//calculate final color;
	vec3 result = ambient + diffuse + specular;
	FragColor = vec4(result, 1.0);
}
