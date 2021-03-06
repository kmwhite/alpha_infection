" Tab Sizes
set tabstop=4
set softtabstop=4
set shiftwidth=4
set noexpandtab

"" Line Length Gutter
" 120 - 3 (' + ') - 1 (buffer) = 116
highlight ColorColumn ctermbg=darkgray guibg=darkgray
set colorcolumn=116
" Change OverLength to be ColorColumn+=1
highlight OverLength ctermbg=darkgray guisp=darkgray
match OverLength /\%117v.\+/

let g:ycm_global_ycm_extra_conf = "./.ycm_extra_conf.py"

"" Expose more things in NerdTree
" Show dot-prefixed files
let NERDTreeShowHidden=1
" Hide object and linker files
let NERDTreeIgnore=['\.o$', '\.a$', '\~$']

" Strip Whitespace at end of lines
fun! StripTrailingWhitespace()
    %s/\s\+$//e
endfun
noremap <silent> <C-a> <Esc>:call StripTrailingWhitespace()<CR>

" Put all autocmds in some augroup ...
augroup local_vimrc_autocmds
    " ... and use au! to clear the group
    au!

    " Call cleanup before file write
    autocmd! BufWritePre * call StripTrailingWhitespace()

    " Set specific language and subtype for project
    autocmd! BufRead,BufNewFile *.h set filetype=cpp.doxygen
    autocmd! BufRead,BufNewFile *.cpp set filetype=cpp.doxygen
augroup END
