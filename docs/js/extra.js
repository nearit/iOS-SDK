$(function(){

  $('.code-swift').replaceWith(function() {
    return $('<div class="code-switcher"> <button class="tab-swift" onclick="switchCode(0)">Swift</button> <button class="tab-objc" onclick="switchCode(1)">Objective-C</button> </div><pre class="code swift"><code>' + this.innerHTML + '</code></pre>');
  });

  $('.code-objc').replaceWith(function() {
    return $('<pre class="code objc"><code>' + this.innerHTML + '</code></pre>');
  });

  switchCode(0);

})

function switchCode(item) {

  // hide all code blocks
  $('.code').hide();

  // show selected code blocks and change selected tab
  switch (item) {
    case 0:
      $('.swift').show();
      $('.tab-swift').addClass('active')
      $('.tab-objc').removeClass('active')
      break;
    case 1:
      $('.objc').show();
      $('.tab-objc').addClass('active')
      $('.tab-swift').removeClass('active')
      break;
    default:
      $('.swift').show();
      $('.tab-swift').addClass('active')
      $('.tab-objc').removeClass('active')
      break;
  }

}
