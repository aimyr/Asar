# Asar
My social project
Synopsis. Our solution, Asar, leverages a neuro interface, inertial sensors, and eye-movement tracking to empower individuals with limited mobility by enabling seamless control of wheelchairs, computers, and smartphones. The name "Asar" reflects an ancient Kazakh tradition of collective effort, where communities come together to help those in need. Rooted in the values of mutual support and survival in the challenging steppe environment, this custom symbolizes unity and shared strength, a legacy that ASAR seeks to honor by addressing the challenges faced by individuals with mobility limitations.

Problem. Globally, 1.3 billion people – about 16% of the global population – currently experience significant disability. (World Health Organisation).  According to statistics, in Kazakhstan in 2024, only 780 out of 724,982 people with disabilities are studying at universities, which says a lot about the inequality in education for disabled children. Nonetheless, despite the presence of qualified specialists among people with disabilities, only 12% of the whole number of people with special needs find employment, which is directly related to their physical limitations. We asked people with disabilities what they needed the most, and we realized that their primary wish was to be independent. Constantly asking for help undermines a person’s dignity; they fear that when they truly need assistance, it may not come. Even if they can earn money and pay for help, it still does not resolve their worries. Because of their physical limitations, they often cannot move freely or use digital devices efficiently in this age of digitalization. As a result, they remain isolated from society, unable to work and grow.  

Solution. We developed a device called Asar, specifically designed to assist individuals with limited mobility in interacting seamlessly with information and communication technologies (ICT). The device integrates three core components: a neurointerface for controlling devices using brain signals, an inertial sensor to detect subtle movements, and a camera that tracks eye movement. This innovative combination enables users to easily control wheelchairs, computers, smartphones, prosthetics, and household appliances.
Our design process was informed by extensive experience in development projects aimed at creating control panels for individuals with spinal cord paralysis. By incorporating feedback from people with disabilities, we identified that the most effective solution lies in integrating and enhancing existing systems with cutting-edge technologies. This approach ensures that individuals with paralysis have access to versatile and practical tools to manage digital devices independently, improving their quality of life and fostering greater independence.

Main Functions of the Device.  
EEG (Electroencephalograph):  Conductive sensors placed on or near the scalp, connected to an electroencephalograph that transmits information to a microcontroller. Controller (Raspberry Pi 4B): A single-board computer that processes data collected by the EEG and an MPU9250 inertial sensor. It enables the user to control devices by tilting or turning their head. MPU9250 Inertial Sensor:  Tracks head and body movements, allowing for motion-based control of devices. Batteries: Provide autonomous power so the device can be used without an external power source. Infrared Camera (Raspberry Pi Camera Module 3 Noir):  Tracks eye movement in any lighting conditions and does not interfere with the user’s vision. Joystick: Offers manual control, which can be more convenient and precise for specific selections Buttons: Used for powering the device on and off and switching modes, giving people with disabilities greater control. Why Not EMG Sensors? EMG sensors require more complex maintenance for the user, so we rely instead on more reliable buttons and position sensors.

Customer Profile. Target Audience:
Primary: Individuals with severe mobility impairments (e.g., spinal cord injury, ALS, cerebral palsy).
Secondary: Caregivers, rehabilitation centers, and nonprofits assisting the disabled.
Needs & Goals:
Independence in daily activities like mobility and communication.
Affordable, intuitive assistive technology.
Enhanced quality of life with dignity and autonomy.
Pain Points:
Reliance on caregivers for basic tasks.
Costly or complex current solutions.
Limited accessibility and customization in assistive devices.

Value Proposition:
ASAR integrates neuro interfaces, sensors, and eye tracking for the intuitive wheelchair, computer, and smartphone control, empowering users with independent and dignified living.
Unique Value Proposition. This topic is very relevant these days. Each of our individual solutions has already been created elsewhere – for example, Neuralink, GlassOuse PRO, and Mouthpad – but all of these exist primarily in developed countries. The problem is that they were all created in developed countries, addressing the needs of disabled people in those nations who can afford to spend large amounts of money, with sufficient assistance provided. In Kazakhstan, for example, it is not the same. Our disabled citizens, even those who are unable to walk, would never be able to purchase an electric wheelchair because they simply do not have enough money. This situation is practically the same in all developing countries. We plan to create a solution that is accessible to everyone and universal so that anyone can use it. It will be innovative, integrating technologies that have not yet been combined. This is what sets us apart from others.

Social Traction. We address the issues of social isolation and dependency faced by people with disabilities, opening doors for them to engage with the world, work, communicate, and develop skills independently. To gain deeper insight into their everyday challenges, we, along with like-minded individuals, established a public organization called UM1T, whose main activity is providing volunteer assistance to people with disabilities. In a short time, our supporters in various cities of Kazakhstan, inspired by this organization, began helping people with disabilities acquire computer literacy skills. We currently operate in three cities and six centers, having trained over one hundred children in programming, design, and computer literacy.

Device Development Traction That is where we found our first test users, who tried our modules with head-motion tracking and tongue-activated buttons. They said it was not entirely convenient, and our biggest concern was reliability: due to saliva exposure, all sensors failed after five days of active use. That is why we are now working on sensors that can better help us achieve our goals. Now we’ve moved on from trying to solve this problem in some elegant way to just solving it any way we can because it turned out to be much more complicated than we initially thought. We want to address this injustice by creating an accessible, universal solution that can finally tackle this issue, at least in Kazakhstan.

Our Achievements. Regarding our team’s progress, we have already won third place in Samsung Solve for Tomorrow Kazakhstan and first place in Red Bull Basement Kazakhstan. We decided to keep refining our project because using only head positioning and tongue-activated buttons proved extremely inconvenient for our testers with mild cerebral palsy. Meanwhile, those whose entire body except for the head is paralyzed, they could not turn the device on, use it properly, or speak at all. We are now determined to bring this project to completion. We also changed the name of project from umit to ASAR.

In the end, I would like to say that we are uniting Kazakhstan to help those most in need. We are making ASAR.
The revenue model will be as follows: the device for data collection the infrared sensor and the radio modules will—excluding EEG— cost $150 to produce and will sell for $200. We are still developing the EEG module, but presumably, it will cost $650 to produce and sell for $750.In addition, we might create a custom control system for each user and each specific wheelchair, which will cost no more than $40—and we won’t charge any extra fee for that. Although we plan to make a small profit, we’d like to run this more like a non-profit project, because we don’t want to profit from other people’s misfortune.

Team. To bring this idea to life, we invested a tremendous amount of time and effort, involving a wide range of people along the way. Individuals with special needs, their caregivers and parents, government representatives, strangers with warm wishes, principals of various social centers, orthodontists, and even a Paralympic champion – all of these incredible people contributed to the development of our product. However, the core team has remained unchanged: Yerassyl Zhumakadyr, an 11th-grade student at NIS PhM in Taraz; Aliyar Sagandykov, another 11th-grade student at NIS PhM in Taraz; and Kudret Ahmet, an 11th-grade student at Gymnasium 45 in Taraz.











Firstly in the code we must get data from prothesis

Then get that data into pc in order to control mause in computer 

Also from pc you can control Android smartphones by changing modes via pitch on 45 degree and right butten 

if you want to control wheel chair change modes via pitch on -45 degree and right butten. Data goes to esp32 then esp use shifter or arduino and control your electrical wheelchair joystick by using servo






https://www.canva.com/design/DAGdNt7HTVg/PEMwJiOz1Z6OwgnxX-dl8w/edit?utm_content=DAGdNt7HTVg&utm_campaign=designshare&utm_medium=link2&utm_source=sharebutton
