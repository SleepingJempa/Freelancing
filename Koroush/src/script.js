import './style.css'
import * as THREE from 'three'
import { OrbitControls } from 'three/examples/jsm/controls/OrbitControls.js'

import { Shape, Sphere } from 'three';
import * as dat from 'dat.gui'


/**
 * Base
 */


// Debug
const parameters ={
    Toruscolor : 0xff,
    Planecolor:0xffffff
}

const gui = new dat.GUI();


// light 

const ambientLight = new THREE.AmbientLight(0x0000,3);


// Textures


const textureLoader = new THREE.TextureLoader()

const cubeTextureLoader = new THREE.CubeTextureLoader()


const doorColorTexture = textureLoader.load('/textures/door/color.jpg')


const environmentMapTexture = cubeTextureLoader.load([
    '/textures/environmentMaps/0/px.jpg',
    '/textures/environmentMaps/0/nx.jpg',
    '/textures/environmentMaps/0/py.jpg',

    '/textures/environmentMaps/0/ny.jpg',
    '/textures/environmentMaps/0/pz.jpg',
    '/textures/environmentMaps/0/nz.jpg'
])


const environmentMapTextureForBox = cubeTextureLoader.load([
    '/textures/environmentMaps/1/px.jpg',
    '/textures/environmentMaps/1/nx.jpg',
    '/textures/environmentMaps/1/py.jpg',

    '/textures/environmentMaps/1/ny.jpg',
    '/textures/environmentMaps/1/pz.jpg',
    '/textures/environmentMaps/1/nz.jpg'
])


// Canvas
const canvas = document.querySelector('canvas.webgl')


// Scene
const scene = new THREE.Scene()


/**
 * Sizes
 */

const sizes = {
    width: window.innerWidth,
    height: window.innerHeight
}


/**
 * Objects
 */
const material = new THREE.MeshBasicMaterial();


//every thing include camera is inside a Box !

const boxMaterial = new THREE.MeshBasicMaterial({envMap:environmentMapTextureForBox,side:THREE.DoubleSide});

const planeMaterial = new THREE.MeshBasicMaterial({map : doorColorTexture});

const sphereMaterial = new THREE.MeshBasicMaterial({envMap:environmentMapTexture})

const torusMaterial = new THREE.MeshBasicMaterial({color:'blue'})

const box = new THREE.Mesh(
    new THREE.BoxGeometry(10,10,10),boxMaterial)



//material.wireframe=true
const sphere = new THREE.Mesh( 
    new THREE.SphereBufferGeometry(0.5,16,16),
    sphereMaterial)
    


const plane = new THREE.Mesh(
    new THREE.PlaneBufferGeometry(1,1), material
)


plane.material.side = THREE.DoubleSide;
const torus = new THREE.Mesh(
    new THREE.TorusBufferGeometry(0.3,0.2,16,32),torusMaterial
)


// big main plane
const mainPlane = new THREE.Mesh(
    new THREE.PlaneBufferGeometry(5, 5),
    planeMaterial
)



scene.add(ambientLight)


gui.add(plane.material,'wireframe')

gui.add(box,'visible').name('enviornment visibility')



gui.
addColor(parameters,'Toruscolor').
onChange(()=>{
    torusMaterial.color.set(parameters.Toruscolor)
}).name('torus color')


gui.addColor(parameters,'Planecolor').onChange(()=>{
    plane.material.color.set(parameters.Planecolor)
})

gui.add(plane.position,'x',-3,3,0.1).name('plane x')

gui.add(plane.position,'y',-3,3,0.1).name('plane y')

gui.add(plane.position,'z',-3,3,0.1).name('plane z')

mainPlane.rotation.x = - Math.PI * 0.5

mainPlane.position.y = - 0.65

sphere.position.x=-1.5
torus.position.x=1.5

scene.add(sphere,plane,torus,mainPlane,box)

window.addEventListener('resize', () =>
{

    // Update sizes
    sizes.width = window.innerWidth
    sizes.height = window.innerHeight


    // Update camera
    camera.aspect = sizes.width / sizes.height
    camera.updateProjectionMatrix()


    // Update renderer
    renderer.setSize(sizes.width, sizes.height)
    renderer.setPixelRatio(Math.min(window.devicePixelRatio, 2))
})

/**
 * Camera
 */
// Base camera
const camera = new THREE.PerspectiveCamera(75, sizes.width / sizes.height, 0.1, 100)

camera.position.x = 1
camera.position.y = 1
camera.position.z = 2

scene.add(camera)

// Controls 
// move camera using mouse 
const controls = new OrbitControls(camera, canvas)

controls.enableDamping = true


/**
 * Renderer
 */
const renderer = new THREE.WebGLRenderer({
    canvas: canvas
})


renderer.setSize(sizes.width, sizes.height)
renderer.setPixelRatio(Math.min(window.devicePixelRatio, 2))


/**
 * Animate
 */
const clock = new THREE.Clock()

const tick = () =>
{
     material.wireframe=false;
    const elapsedTime = clock.getElapsedTime()

    sphere.rotation.y=elapsedTime*0.1
    sphere.position.z=Math.sin(Math.PI*elapsedTime)/6
    plane.rotation.y=elapsedTime*0.1
    torus.rotation.y=elapsedTime*0.1
    sphere.rotation.x=elapsedTime*0.1
    plane.rotation.x=elapsedTime*0.1
    torus.rotation.x=elapsedTime*0.1


    // Update controls
    controls.update()


    // Render
    renderer.render(scene, camera)

    // Call tick again on the next frame
    window.requestAnimationFrame(tick)
}

tick()