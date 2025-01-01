"use strict";

let l = console.log;
if (typeof document !== 'undefined') {
    function by_class(cls) {
        return document.getElementsByClassName(cls);
    }

    const all_selects = by_class("select");
    const all_data    = by_class("data");
    const all_labels  = by_class("label");
    const all_truth_tables = by_class("truth-table");

    function hide(elem) {
        elem.style.display = "none";
    }

    function show(elem, kind) {
        if (kind === undefined) {
            elem.style.display = "block";
        } else {
            elem.style.display = kind;
        }
    }

    function show_tab(target, code) {
        for (let elem of by_class("data " + code)) {
            if (elem.classList.contains(target)) {
                show(elem);
            } else {
                hide(elem);
            }
        }

        for (let elem of by_class("select " + code)) {
            elem.classList.toggle("selected", elem.classList.contains(target));
        }
    }

    function expand_all() {
        for (let elem of all_selects) {
            hide(elem);
        }
        for (let elem of all_labels) {
            show(elem);
        }
        for (let elem of all_data) {
            show(elem);
        }
    }

    function collapse_all() {
        for (let elem of all_selects) {
            show(elem, "inline-block");
        }
        for (let elem of all_labels) {
            hide(elem);
        }
        for (let elem of by_class("select selected")) {
            elem.click();
        }
    }

    function show_truth_tables(flag) {
        for (let elem of all_truth_tables) {
            if (flag) {
                show(elem);
            } else {
                hide(elem);
            }
        }
    }

    document.addEventListener('DOMContentLoaded', function() {
        for (let elem of all_selects) {
            const fields = elem.id.split('-');
            const target = fields[1];
            const code   = fields[2];

            elem.addEventListener("click", function(event) {
                if (!event.target.classList.contains("disabled")) {
                    show_tab(target, code);
                }
            });
        }

        for (let elem of all_labels) {
            hide(elem);
        }

        const target = "sse";
        for (let code=0; code < 256; code++) {
            const cls = "fn" + code;
            show_tab(target, cls);
        }

        document.getElementById("expand-all").addEventListener("click", function(ev) {
            if (ev.target.checked) {
                expand_all();
            } else {
                collapse_all();
            }
        }, false);

        document.getElementById("truth-table").addEventListener("click", function(ev) {
            show_truth_tables(ev.target.checked);
        }, false);

    }, false);
}
