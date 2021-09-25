
[Material]
{
    _Color : ("MyColor", vec3);
    _noiseOffset : ("NoiseOffset", vec2);
    _Color : ("MyColor", float);
    _Color : ("MyColor", Texture2D);
    _Color : ("MyColor", vec3);
    _Color : ("MyColor", vec3);
}

[Vertex]
{
    #version 330 core

    layout (location = 0) in vec3 aPos;
    layout (location = 1) in vec3 aNormal;

    uniform mat4 model;
    uniform mat4 projection;

    uniform vec3 MyColor;

    out vec3 objColor;
    out vec3 Normal;
    out vec3 FragPos;
    out vec3 DiffuseColor;
    
    vec3 cvColor(int r, int g, int b)
    {
        return vec3(r/255.0f,g/255.0f,b/255.0f);
    }


    void main()
    {
        gl_Position = projection * model * vec4(aPos, 1.0f);
        FragPos = vec3(model * vec4(aPos, 1.0f));
        Normal = aNormal; 
        objColor = cvColor(255,255,255);
    }

}

[Fragment]
{
    #version 330 core

    out vec4 FragColor;

    in vec3 Normal;  
    in vec3 objColor;
    in vec3 FragPos;


    void main()
    {

        //ambient
        vec3 lightColor = vec3(1,1,1);
        vec3 lightDirection = vec3(-0.2f, -1.0f, -0.3f);
        vec3 lightPos = vec3(1,5,1);
        float ambientStrenght = 0.1f;

        vec3 ambient = ambientStrenght * lightColor ;



        // diffuse
        vec3 norm = normalize(Normal);
        vec3 lightDir = normalize(-lightDirection);
        float diff = max(dot(norm, lightDir), 0.0);
        vec3 diffuse = vec3(0.5f, 0.5f, 0.5f) * diff * lightColor;


        //vec3 result = (ambient + diffuse) * DiffuseColor;
        vec3 result = (diffuse + ambient) * objColor;


        FragColor = vec4(result, 1.0);
    }

}