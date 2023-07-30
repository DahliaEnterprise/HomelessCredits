<html>
<head>

    <script>
        //Global
            //Constants

            //Generate Credits States
            var generate_credits_last_percela_informacion = [];


        //Functions


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
                        information_for_generatecredits_worker["difficulty"] = 1;
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
