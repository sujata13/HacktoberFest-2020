var player1=prompt('Player One(RED): Enter your name');
var player1_color='rgb(182, 11, 11)';
var player2=prompt('Player One(BLUE): Enter your name');
var player2_color='rgb(45, 39, 236)';

var game_on=true;
var table=$('table tr')

function report_win(row_num,col_num){
  console.log('You won starting at this row, col:')
  console.log(row_num)
  console.log(col_num)
}

function change_color(row_index,col_index,color){
  return table.eq(row_index).find('td').eq(col_index).find('button').css('background-color',color)
}

function return_color(row_index,col_index){
  return table.eq(row_index).find('td').eq(col_index).find('button').css('background-color')
}

function check_bottom(col_index){
  var color_report=return_color(5,col_index)
  for (var row = 5; row>=0 ; row--) {
    color_report=return_color(row,col_index)
    if(color_report === 'rgb(128, 128, 128)'){
      return row
    }
  }
}

function color_match_check(one,two,three,four){
  return (one===two && one===three && one===four && one!== 'rgb(128, 128, 128)' && one!==undefined)

}


function horizontal_win_check(){
  for (var row=0;row<6;row++){
    for(var col=0;col<4;col++){
      if(color_match_check(return_color(row,col),return_color(row,col+1),return_color(row,col+2),return_color(row,col+3))){
        console.log('horiz')
        report_win(row,col)
        return true
      }else{
        continue
      }
    }
  }
}

function vertical_win_check(){
  for(var col=0;col<7;col++){
    for(var row=0;row<3;row++){
      if(color_match_check(return_color(row,col),return_color(row+1,col),return_color(row+2,col),return_color(row+3,col))){
        console.log('vertical')
        report_win(row,col)
        return true
      }else{
        continue
      }
    }
  }
}

function diagonal_win_check(){
  for(var col=0;col<=4;col++){
    for(var row=0;row<=6;row++){
      if(color_match_check(return_color(row,col),return_color(row+1,col+1),return_color(row+2,col+2),return_color(row+3,col+3))){
        console.log('diag 1')
        report_win(row,col)
        return true
      }else if(color_match_check(return_color(row,col),return_color(row-1,col+1),return_color(row-2,col+2),return_color(row-3,col+3))){
          console.log('diag 2')
          report_win(row,col)
          return true
      }else{
        continue
      }
    }
  }
}

//START WITH PLAYER1
var current_player=1
var current_name=player1
var current_color=player1_color

$('h3').text(player1+" it is your turn, pick a column")

$('.board button').on('click',function(){
  var col=$(this).closest('td').index();
  var bottom_avail=check_bottom(col);
  change_color(bottom_avail,col,current_color)
  if(horizontal_win_check() || vertical_win_check() || diagonal_win_check()){
    $('h1').text(current_name+" wins!")
    $('h3').fadeOut('fast');
    $('h2').fadeOut('fast');
  }
  current_player=current_player*-1

  if(current_player === 1){
    if(return_color(0,0)!='rgb(128, 128, 128)' && return_color(0,1)!='rgb(128, 128, 128)' && return_color(0,2)!='rgb(128, 128, 128)' && return_color(0,3)!='rgb(128, 128, 128)' && return_color(0,4)!='rgb(128, 128, 128)' && return_color(0,5)!='rgb(128, 128, 128)' && return_color(0,6)!='rgb(128, 128, 128)'){
      $('h1').text("Draw:/")
      $('h3').fadeOut('fast');
      $('h2').fadeOut('fast');
    }
    current_name=player1
    $('h3').text(current_name+" it is your turn")
    current_color=player1_color
  }else{
    if(return_color(0,0)!='rgb(128, 128, 128)' && return_color(0,1)!='rgb(128, 128, 128)' && return_color(0,2)!='rgb(128, 128, 128)' && return_color(0,3)!='rgb(128, 128, 128)' && return_color(0,4)!='rgb(128, 128, 128)' && return_color(0,5)!='rgb(128, 128, 128)' && return_color(0,6)!='rgb(128, 128, 128)'){
      $('h1').text("Draw:/")
      $('h3').fadeOut('fast');
      $('h2').fadeOut('fast');
    }
    current_name=player2
    $('h3').text(current_name+" it is your turn")
    current_color=player2_color
  }
})
