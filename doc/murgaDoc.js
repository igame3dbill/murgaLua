function pageIndex(pageTitle)
{
    var contents = "";
    var all = document.body.childNodes;
    var contents2 = "";
    var text = "";
    var found = false;
    var h3 = false;
    contents2 += '<b>' + pageTitle + '</b><ul>';
    for (var i = 0; i < all.length; ++i) {
        if (all[i].nodeName == "H2" || all[i].nodeName == "H3") {
            if (all[i].nodeName == "H2") {
                if (h3) contents2 += '</ul>';
                h3 = false;
            }
            if (all[i].nodeName == "H3") {
                if (!h3) contents2 += '<ul>';
                h3 = true;
            }
            found = true;
            text = all[i].innerHTML.replace(/<[^>]+>/g,"");
            all[i].innerHTML = '<a name="'+text+'">'+text+'</a>';
            contents2 += '<li><a href="#'+text+'">'+text+'</a></li>';
        }
    }
    contents2 += '</ul>';
    if (found) {
        if (contents) contents += '<br>';
        contents += contents2;
    }
    if (contents) {
        document.getElementById("contents").className = "contents";
        document.getElementById("contents").innerHTML = contents;
    }
}
