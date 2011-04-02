-- main_loop test

function init(ctx)
   add_timer(5.00, callback)
end

function callback(ctx)
   ctx:set_status(DONE)
   return false
end

function next(ctx)
   if ctx:get_status() == DONE then
      ctx:set_status(END)
   end
end
