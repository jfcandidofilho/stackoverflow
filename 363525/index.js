var resultados = [ 
		{ 
			texto: "Clique aqui para abrir o poderoso <a href=\"https://www.google.com\">Google</a>!",
			texto2: "Another object"
		}, 
		"Outro item do array",
		"Mais um item do array"
	];
	
var popular = function(id){

	alvo = document.getElementById(id);
	
	alvo.innerHTML = resultados[0].texto;

};
