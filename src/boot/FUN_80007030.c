/* FUN_80007030
 * image   boot (boot), base 0x80000480
 * address 0x80007030  body 0x80007030..0x800070b3  size 132 B
 * body sha256 b4d8eddf2f34390e294c45dfd95afff19908123d58012573a9660350be0914f2
 * provider record sha256 7d835df192fe48242d39ab14f6551833489670dc5ec0321b418034abac0e98d0
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_80007030(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  
  uVar3 = FUN_800072e0();
  iVar4 = FUN_80007000();
  iVar2 = _DAT_8001782c;
  iVar1 = _DAT_80017828;
  uVar5 = iVar4 - _DAT_80017820;
  FUN_80007300(uVar3);
  return iVar1 + (uint)(iVar2 + uVar5 < uVar5);
}
