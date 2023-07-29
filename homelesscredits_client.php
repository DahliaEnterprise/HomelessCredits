<html>
<head>

    <script>
        //Global
            //Constants
            const alphabet_table = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

            //Generate Credits States
            var generate_credits_last_percela_informacion = [];


        //Functions
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

        function get_balance_from_server()
        {

        }

        //Generate Credits
        var generatecredits_xmlhttprequest = new XMLHttpRequest();
        var generatecredits_worker;
        function begin_generate_credits()
        {
            generatecredits_xmlhttprequest.onreadystatechange = function()
            {
                if(this.readyState == 4 && this.status == 200)
                {
                    //Store last parcela informacion
                    generate_credits_last_parcela_informacion = JSON.parse(generatecredits_xmlhttprequest.responseText);
                    console.log(generate_credits_last_parcela_informacion["parcela_informacion_available"]);
                    if(generate_credits_last_parcela_informacion["parcela_informacion_available"] == 0)
                    {
                        let information_for_generatecredits_worker = [];
                        information_for_generatecredits_worker["first_parcela"] = 1;
                        generatecredits_worker = new Worker("/homelesscredits_generate_credits_worker.js");
                        //Send the worker a message
                        generatecredits_worker.postMessage(information_for_generatecredits_worker);
                        //Handle the message
                        /*generatecredits_worker.addEventListener("message", event => {
                            /*if (event.data) {
                                club.appendChild(listItem)
                            }*
                        });*/
                    }else{
                        //generate_credits(0);
                    }

                    //generate_credits();
                }
            };
            generatecredits_xmlhttprequest.open("GET", "/homelesscredits_server_get_next_parcela.php", true);
            generatecredits_xmlhttprequest.send();
        }

        /*
        async function generate_credits(generate_first_parcela)
        {
            let keep_attempting_to_generate_credits = 1;
            while(keep_attempting_to_generate_credits == 1)
            {
                let string_to_rotate = generate_random_string(32);
                const array_for_one_random_integer = new Uint32Array(1);
                self.crypto.getRandomValues(array_for_one_random_integer);

                string_to_rotate = rotate_string_swap_character_per_character_position(string_to_rotate, 500000);

                if(string_to_rotate[0] == "0")
                {
                    console.log(string_to_rotate);
                    keep_attempting_to_generate_credits = 0;
                    console.log("found level one parcela");
                }
            }
        }
        */
        //END Generate Credits

        //Entry Point
        function entry_function()
        {
            //UNIT TESTING
            /* GENERATE COIN PRE CURSOR
            let string_to_rotate = generate_random_string(32);
            const array_for_one_random_integer = new Uint32Array(1);
            self.crypto.getRandomValues(array_for_one_random_integer);

            string_to_rotate = rotate_string_swap_character_per_character_position(string_to_rotate, 1000);
            console.log(string_to_rotate);
            */

            //PRODUCTION
            //const string_to_rotate = "TESTING";
            //rotate_string(string_to_rotate);
        }
    </script>
</head>
<body onLoad="entry_function();">
<div style="text-align:center;" id="balance">Loading Balance.</div>
<div style="text-align:center;"><a href="javascript:void(0);" onClick="begin_generate_credits();">Generate Credits</a></div>
<div id="parcela_informacion" style="text-align:center;">
    Parcela Information<br/>
    HERE
</div>
</body>
</html>
