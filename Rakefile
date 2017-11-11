dir = File.dirname(__FILE__)

task :transpile do
  Dir.chdir "./main"
  sh "posixvalac -C #{dir}/main/main.vala --pkg esp32 --vapidir=#{dir}/vapi"
  Dir.chdir "../"
end

task :make => :transpile do
  sh "make"
end
