#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <learnopengl/filesystem.h>
#include <learnopengl/shader_m.h>
#include <learnopengl/camera.h>
#include <learnopengl/model.h>

#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void processInput(GLFWwindow* window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

// camera
Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));
float lastX = SCR_WIDTH / 2.0f;
float lastY = SCR_HEIGHT / 2.0f;
bool firstMouse = true;

float z_depth = -7.0f;

// timing
float deltaTime = 0.0f;
float lastFrame = 0.0f;
bool is_paused = false;
float camera_rotation_speed = 0.05f;

#define TOTAL_STARS 300

float star_coordinates_x[TOTAL_STARS];
float star_coordinates_y[TOTAL_STARS];
float star_coordinates_z[TOTAL_STARS];
float camera_rotation_x = 0;
float camera_rotation_y = 0;

int main()
{
    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    for (int i = 0; i < TOTAL_STARS; i++) {
        star_coordinates_x[i] = rand() % 50 - 25.0f;
        star_coordinates_y[i] = rand() % 50 - 25.0f;
        star_coordinates_z[i] = rand() % 50 - 25.0f;
    }

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // glfw window creation
    // --------------------
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Galaxy Destroyer", NULL, NULL);
    if (window == NULL) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetScrollCallback(window, scroll_callback);

    // tell GLFW to capture our mouse
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // tell stb_image.h to flip loaded texture's on the y-axis (before loading model).
    stbi_set_flip_vertically_on_load(true);

    // configure global opengl state
    // -----------------------------
    glEnable(GL_DEPTH_TEST);

    // build and compile shaders
    // -------------------------
    Shader ourShader("1.model_loading.vs", "1.model_loading.fs");

    // load models
    // -----------
    Model earth(FileSystem::getPath("resources/Earth/Earth.obj"));
    Model sun(FileSystem::getPath("resources/Sun/Sun.obj"));
    Model moon(FileSystem::getPath("resources/Moon/Moon.obj"));


    // draw in wireframe
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    float elapsed_time = 0.0f;
    // render loop
    // -----------
    while (!glfwWindowShouldClose(window))
    {
        // per-frame time logic
        // --------------------
        float currentFrame = static_cast<float>(glfwGetTime());
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        if (!is_paused) {
            elapsed_time = elapsed_time + deltaTime;
        }

        // input
        // -----
        processInput(window);

        // render
        // ------
        glClearColor(0.05f, 0.05f, 0.05f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // don't forget to enable shader before setting uniforms
        ourShader.use();

        // view/projection transformations
        glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);

        glm::mat4 view = camera.GetViewMatrix();
        view = glm::translate(view, glm::vec3(0.0f, 0.0f, z_depth));        
        view = glm::rotate(view, camera_rotation_x, glm::vec3(1.0f, 0.0f, 0.0f));
        view = glm::rotate(view, camera_rotation_y, glm::vec3(0.0f, 1.0f, 0.0f));
       
        ourShader.setMat4("projection", projection);
        ourShader.setMat4("view", view);


        // render the loaded model
        glm::mat4 model = glm::mat4(1.0f);

        // translate it down so it's at the center of the scene                        
        model = glm::translate(model, glm::vec3(-1.0f, -0.8f, -1.0f)); // translate it down so it's at the center of the scene                
        ourShader.setMat4("model", model);
        sun.Draw(ourShader);

        {
            glm::mat4 model = glm::mat4(1.0f);                     
            model = glm::rotate(model, elapsed_time * 1.0f, glm::vec3(0.0f, 1.0f, 0.0f)); // translate it down so it's at the center of the scene
            model = glm::translate(model, glm::vec3(4.0f, 0.0f, 0.0f)); // translate it down so it's at the center of the scene           
            model = glm::rotate(model, elapsed_time*0.05f, glm::vec3(0.0f, 1.0f, 0.0f)); // translate it down so it's at the center of the scene
            model = glm::scale(model, glm::vec3(0.1f, 0.1f, 0.1f));	// it's a bit too big for our scene, so scale it down
            ourShader.setMat4("model", model);
            earth.Draw(ourShader);

            {
                glm::mat4 moon_model = model;
                moon_model = glm::rotate(moon_model, 180 + elapsed_time * 3.0f, glm::vec3(0.0f, 1.0f, 0.0f)); // translate it down so it's at the center of the scene
                moon_model = glm::translate(moon_model, glm::vec3(7.0f, 0.0f, 0.0f)); // translate it down so it's at the center of the scene           
                moon_model = glm::scale(moon_model, glm::vec3(0.5f, 0.5f, 0.5f));	// it's a bit too big for our scene, so scale it down
                ourShader.setMat4("model", moon_model);
                moon.Draw(ourShader);
            }            
        }
        
        for (int i = 0; i < TOTAL_STARS; i++) {
            glm::mat4 model = glm::mat4(1.0f);
            model = glm::translate(model, glm::vec3(star_coordinates_x[i], star_coordinates_y[i], star_coordinates_z[i])); // translate it down so it's at the center of the scene                        
            model = glm::scale(model, glm::vec3(0.02f, 0.02f, 0.02f));
            ourShader.setMat4("model", model);
            sun.Draw(ourShader);
        }

      

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
    return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    if (!is_paused) {
        if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
            camera.ProcessKeyboard(FORWARD, deltaTime);
        if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
            camera.ProcessKeyboard(BACKWARD, deltaTime);
        if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
            camera.ProcessKeyboard(LEFT, deltaTime);
        if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
            camera.ProcessKeyboard(RIGHT, deltaTime);


        if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) {
            camera_rotation_y -= camera_rotation_speed;
        }

        if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
            camera_rotation_y += camera_rotation_speed;
        }

        if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) {
            camera_rotation_x -= camera_rotation_speed;
        }

        if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) {
            camera_rotation_x += camera_rotation_speed;
        }

            


    }

    if (glfwGetKey(window, GLFW_KEY_P) == GLFW_PRESS)
        is_paused = true;

    if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS)
        is_paused = false;
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}

// glfw: whenever the mouse moves, this callback is called
// -------------------------------------------------------
void mouse_callback(GLFWwindow* window, double xposIn, double yposIn)
{
    float xpos = static_cast<float>(xposIn);
    float ypos = static_cast<float>(yposIn);

    if (!is_paused) {

        if (firstMouse)
        {
            lastX = xpos;
            lastY = ypos;
            firstMouse = false;
        }

        float xoffset = xpos - lastX;
        float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top

        lastX = xpos;
        lastY = ypos;

        camera.ProcessMouseMovement(xoffset, yoffset);
    }
}

// glfw: whenever the mouse scroll wheel scrolls, this callback is called
// ----------------------------------------------------------------------
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    if (!is_paused) {
        camera.ProcessMouseScroll(static_cast<float>(yoffset));
    }
}
