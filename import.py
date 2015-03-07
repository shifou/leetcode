#code I found online which can spider all the code from leetcode with bugs fixed to make it work correctly. 
import urllib2
import cookielib
import urllib
import os
mydir = r'path'
myhost = r'https://oj.leetcode.com' 
def saveCode(code,title):
    global mydir
    path = mydir +title +'.cpp'
    e = os.path.exists(path)
    if e:
        print "file exist"
        return None
    f = open(path,'w')
    f.write(code)
    f.close()
def downloadCode(refer,codeadd,title):
    global headers
    global urlOpener
    global myhost
    headers['Referer'] = refer
    request = urllib2.Request(codeadd,headers=headers)
    url = urlOpener.open(request)
    all = url.read()
    tar = "storage.put('cpp',"
    index = all.find(tar,0)
    start = all.find('class Solution',index)
    finis = all.find("');",start)
    code = all[start:finis]
    toCpp = {'\u000D':'\n','\u000A':'','\u003B':';','\u003C':'<','\u003E':'>','\u003D':'=',\
    '\u0026':'&','\u002D':'-','\u0022':'"','\u0009':'\t','\u0027':"'",'\u005C':'\\'}
    for key in toCpp.keys():
         code = code.replace(key,toCpp[key])
    #print code
    saveCode(code,title)

def findCode(address,title):
    global headers
    global urlOpener
    global myhost
    headers['Referer'] = address
    address += 'submissions/'
    print 'now is dealing ' + address + ': ' + title 
    request = urllib2.Request(address,headers=headers)
    url = urlOpener.open(request)
    all = url.read()
    tar = 'class="text-danger status-accepted"'
    index = all.find(tar,0)
    start = all.find('href="',index)
    finis = all.find('">',start)
    #print myhost + all[start + 6:finis]
    downloadCode(address,myhost + all[start + 6:finis],title) 

def findAdd(page):
    index = 0
    while 1:
        index = page.find('class="ac"',index)
        if index != -1:
            index += 1
            start = page.find('<a href="',index)
            finis = page.find('">',start)
            tmpfin = page.find('<',finis)
            title = page[finis + 2:tmpfin]
            #print myhost + page[start + 9:finis],title
            findCode(myhost + page[start + 9:finis],title)
            break;
        else:
            break





cookie = cookielib.CookieJar()
handler = urllib2.HTTPCookieProcessor(cookie)
urlOpener = urllib2.build_opener(handler)
urlOpener.open('https://oj.leetcode.com/')

csrftoken = ""
for ck in cookie:
	csrftoken = ck.value
	#print csrftoken


login = "username"
mypwd = "password" 


values = {'csrfmiddlewaretoken':csrftoken,'login':login,'password':mypwd,'remember':'on'}
values = urllib.urlencode(values)
headers = {'User-Agent':'Mozilla/5.0 (Windows; U; Windows NT 6.1; en-US; rv:1.9.1.6)Gecko/20091201 Firefox/3.5.6', \
'Origin':'https://oj.leetcode.com','Referer':'https://oj.leetcode.com/accounts/login/'}



request = urllib2.Request("https://oj.leetcode.com/accounts/login/",values,headers=headers)

url = urlOpener.open(request)

page = url.read()
findAdd(page)


