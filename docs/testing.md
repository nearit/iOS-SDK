# Testing

## Manual recipe trigger

To help with testing, you can manually trigger a recipe.
The `manager` instance has a getter for the `cached` recipe list. 
You can get the list of recipes with the method:

<div class="code-swift">
manager.recipes()
</div>
<div class="code-objc">
[manager recipes];
</div>
Once you pick the recipe you want to test, use this method to trigger it:

<div class="code-swift">
let id = recipe.ID
manager.processRecipe(id)
</div>
<div class="code-objc">
NSString *ID = recipe.ID
[manager processRecipeWithId:ID];
</div>
