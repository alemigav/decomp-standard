/* FUN_80006f60
 * image   boot (boot), base 0x80000480
 * address 0x80006f60  body 0x80006f60..0x80006ff3  size 148 B
 * body sha256 451318a8367c4f0fee39e814eb4fde8ffc361ca41cde091633d68e426a1b648b
 * provider record sha256 0d8ab6cf77b6f97c24e3e74765eb4e1bd42ae9be573096c8847caafbf0a5053a
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_80006f60(undefined4 param_1,undefined2 *param_2,int param_3)

{
  undefined4 uVar1;
  undefined2 uVar2;
  
  if (_DAT_800128f0 == 0) {
    uVar1 = 0xffffffff;
  }
  else {
    *(undefined4 *)(param_2 + 10) = param_1;
    if (param_3 == 0) {
      uVar2 = 0xf;
    }
    else {
      uVar2 = 0x10;
    }
    *param_2 = uVar2;
    if (*(char *)(param_2 + 1) == '\x01') {
      uVar1 = FUN_8000be30();
      uVar1 = FUN_80007450(uVar1,param_2,0);
    }
    else {
      uVar1 = FUN_8000be30();
      uVar1 = osSendMesg(uVar1,param_2,0);
    }
  }
  return uVar1;
}
