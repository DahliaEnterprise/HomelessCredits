// addEventListener is directly accessible in worker file
addEventListener("message", event => {
    let reduced_string = reduce_or_expand_string("SDFJSDFSDFHSADFGDSFHSDFJSDFH77675DFGD43TTFSDSRWEFDFGDGEGREGDFDFESRERYIUOTRF5", 32, 500000);

    console.log(event.data);
    let keep_attempting_to_generate = 1;
    while(keep_attempting_to_generate == 1)
    {
        let string_to_rotate = generate_random_string(32);
        const array_for_one_random_integer = new Uint32Array(1);
        self.crypto.getRandomValues(array_for_one_random_integer);

        string_to_rotate = rotate_string_swap_character_per_character_position(string_to_rotate, 500000);
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
            console.log(total_difficulty_detected);
            console.log(string_to_rotate);
            keep_attempting_to_generate = 0;
        }

    }


});

const alphabet_table = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";


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

function reduce_or_expand_string(string_to_scale, target_size, iterations)
{
    //Reduce by every other character or expand by every other character
    if(string_to_scale.length > target_size)
    {
        let iterations_exponentional = 2;
        let string_to_scale_cursor_index = 0;
        let reduced_string = "";
        let continue_reducing_string = 1;
        while(continue_reducing_string == 1)
        {
            //Move cursor in a ringbuffer fashion until target iterations have been aquired

            let target_iterations = iterations_exponentional * (string_to_scale_cursor_index + 2);
            console.log(target_iterations);
            let iterations = 0;
            while(iterations < target_iterations)
            {
                string_to_scale_cursor_index = string_to_scale_cursor_index + 1;
                if(string_to_scale_cursor_index == string_to_scale.length)
                {
                    string_to_scale_cursor_index = 0;
                }
                iterations = iterations + 1;
            }
                //Now that the cursor is moved, pull character
                reduced_string = reduced_string + "" + string_to_scale[string_to_scale_cursor_index];
                iterations_exponentional = iterations_exponentional + 1;
            //Stop reducing string?
            if(reduced_string.length == target_size)
            {
                continue_reducing_string = 0;
            }
        }
        console.log(reduced_string);
    }else if(string_to_scale.length < target_size)
    {
        console.log("TODO EXPAND");
    }
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