

with open("web/index.html") as f:
    html = f.read()
    html = html.replace(
        # '<script src="js/editor.min.js"></script>',
        '<script type=module src="js/editor.min.js"></script>',
        '<script>\n%s\n</script>\n')

with open("web/js/editor.min.js") as js:
    with open("build/index.html",'w') as index_html:
        content = js.read()
        index_html.write(html % content)
