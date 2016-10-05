Projeto Taboão - Branchs

Nosso padrão de branch será: 
- projeto_taboao-<nome_da_pasta_secundaria>-<tarefa>

Exemplo:
"taboao_mainScreen-05"

<---------------------------------------------->

Para criar uma branch use o comando:
`$ git checkout -b taboao_mainScreen-05`

Para add ou commitar o processo é o mesmo da origin/master.
`$ git commit -a -m 'consertei o bug'`


Para dar um git push faça: 
`$ git push --set-upstream origin taboao_mainScreen-05`

Criou uma branch bosta, errou, sei lá. Para deletar use:
`$ git branch -D taboao_mainScreen-05`

Voltar para a master:
`$ git checkout master`

Dar um merge da branch, depois de finalizar com a master para colocar em produção:
`$ git checkout master`
$ git merge  taboao_mainScreen-05
