// addEventListener is directly accessible in worker file
addEventListener("message", event => {
console.log("MESSAGE");
    let keep_attempting_to_generate = 1;
    while(keep_attempting_to_generate == 1)
    {
        //EMULATE string as if its a concaconated entry for approval by the chain.
        let string_to_rotate = generate_random_string(32);

        let concat_string_plus_nonce = event.data["concatconated_string"] + "" + string_to_rotate;
        //console.log(concat_string_plus_nonce);
        let reduced_string = reduce_string(concat_string_plus_nonce, 32, 10000);


        //Reduce string for hash rotation.
        string_to_rotate = "" + reduced_string;

        string_to_rotate = rotate_string_swap_character_per_character_position(string_to_rotate, 500000);
        console.log(string_to_rotate);
        let total_difficulty_to_obtain = event.data["difficulty"];
        let total_difficulty_detected = 0;
        let detect_difficulty_current_index = string_to_rotate.length - 1;
        let keep_detecting_difficulty = 1;
        while(keep_detecting_difficulty == 1)
        {
            if(string_to_rotate[detect_difficulty_current_index] == "0")
            {
                console.log("zero");
                console.log(string_to_rotate);
                detect_difficulty_current_index = detect_difficulty_current_index - 1;
                total_difficulty_detected = total_difficulty_detected + 1;
            }else{
                keep_detecting_difficulty = 0;
            }
        }

        if(total_difficulty_detected >= total_difficulty_to_obtain)
        {

            keep_attempting_to_generate = 0;
        }

    }

});

const alphabet_table = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789{}\"' ";


//Rotate character based on iterations amongst the alphabet table
function rotate_character(character, iterations)
{
    let output = -1;

    //Determine current index amongst the alphabet table.
    let current_character_index = -1;
    //Execute
    let index = 0;
    while(index < alphabet_table.length)
    {
        if(alphabet_table[index] === character)
        {
            current_character_index = index;
            index = alphabet_table.length;
        }else{
            //Next character
            index = index + 1;
        }
    }

    //Fault occured(No allowed character found)?
    if(current_character_index > -1)
    {
        //No fault occured
        //Execute Rotate Character
        let rotate_character_index = current_character_index;
        let iterations_consumed = 0;
        let continue_rotating = 1;
        while(continue_rotating == 1)
        {
            rotate_character_index = rotate_character_index + 1;
            //Continue loop through alphabet table
            if(rotate_character_index == alphabet_table.length)
            {
                rotate_character_index = 0;
            }

            iterations_consumed = iterations_consumed + 1;

            if(iterations_consumed == iterations)
            {
                output = rotate_character_index;
                continue_rotating = 0;
            }
        }
    }

    //Return
    return output;
}

function rotate_string_swap_character_per_character_position(string_to_rotate, iterations)
{
    let output = "";

    //Execute rotate each character per character position
    let index = 0;
    while(index < string_to_rotate.length)
    {
        let exponential_rotation_strength = (index + 2) * iterations;//Ensure it is always above 1 to enable randomness
        let new_character_index = rotate_character(string_to_rotate[index], exponential_rotation_strength);
        output = output + "" + alphabet_table[new_character_index];
        index = index + 1;
    }

    return output;
}

function reduce_string(string_to_scale, target_size, iterations)
{
    //This function assumes that string_to_scale.length is greater than target_size.
    //This function must reduce the string in a predictable manner. (no random)

    //Begin reducing.
        let iterations_magnitude = 2;
        let reduced_string = "";
        let total_characters_appended_to_reduced_string = 0;
        let string_to_scale_index = 0;
        let keep_building_reduced_string = 1;
        while(keep_building_reduced_string == 1)
        {
            let counter_of_iterations = 0;
            while(counter_of_iterations < (iterations_magnitude * iterations))
            {
                string_to_scale_index = string_to_scale_index + 1;
                if(string_to_scale_index == string_to_scale.length)
                {
                    string_to_scale_index = 0;
                }
                counter_of_iterations = counter_of_iterations + 1;
            }

            reduced_string = reduced_string + string_to_scale[string_to_scale_index];
            iterations_magnitude = iterations_magnitude + 1;

            total_characters_appended_to_reduced_string = total_characters_appended_to_reduced_string + 1;
            if(total_characters_appended_to_reduced_string == target_size)
            {
                keep_building_reduced_string = 0;
            }
        }
    return reduced_string;
}

//Random Assistive Functions
function generate_random_index_amongst_alphabet_table()
{
    let output = -1;

    let keep_generating = 1;
    while(keep_generating == 1)
    {
        const array_for_one_random_integer = new Uint8Array(1);
        self.crypto.getRandomValues(array_for_one_random_integer);

        if(array_for_one_random_integer[0] < alphabet_table.length)
        {
            keep_generating = 0;
            output = array_for_one_random_integer[0];
        }


    }

    return output;
}

function generate_random_string(string_length_to_generate)
{
    let output = "";
    let total_generated = 0;
    while(total_generated < string_length_to_generate)
    {
        output = output + "" + alphabet_table[generate_random_index_amongst_alphabet_table()];
        total_generated = total_generated + 1;
    }

    return output;
}
