/* FUN_80031c14
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80031c14  body 0x80031c14..0x80031fef  size 988 B
 * body sha256 c34e683f521511c855e5babef38896faeb7b5c727164668aa89bcf4e67442d46
 * provider record sha256 a26a34c21cdcfe34cb71dce9bd806cf86a5c633f219cae9cf0b7b47a5dff6034
 * callees 10 direct (10 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Removing unreachable block (ram,0x80031e20) */

uint FUN_80031c14(int param_1,int param_2,int param_3)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined *puVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  uVar5 = (uint)*(byte *)(param_2 + 8);
  if (uVar5 - 0x50 < 0xb) {
    if ((*(byte *)(param_2 + 8) & 1) == 0) {
      iVar2 = FUN_800837ac(&DAT_800e8eb8,5);
      if (iVar2 != 0) {
        uVar5 = 0x58;
      }
      iVar2 = FUN_800837ac(&DAT_800e8eb8,0xf);
      if (iVar2 != 0) {
        uVar5 = 0x5a;
      }
    }
    else {
      iVar2 = FUN_800837ac(&DAT_800e8eb8,6);
      if (iVar2 != 0) {
        uVar5 = 0x59;
      }
    }
  }
  if (DAT_800e110c < 0) {
    if (DAT_800e1138 - 0xc < 2) {
      puVar4 = &UNK_80128ed0;
    }
    else {
      puVar4 = &UNK_80128a10;
    }
  }
  else if (DAT_800e1138 == 0xe) {
    puVar4 = &UNK_80128c70;
  }
  else {
    puVar4 = &UNK_801287b0;
  }
  uVar6 = param_3 + 7U & 0xfffffff8;
  uVar1 = *(undefined2 *)(puVar4 + ((uVar5 - 0x10) * 4 + 2) * 2);
  uVar5 = (uint)*(ushort *)((int)(puVar4 + ((uVar5 - 0x10) * 4 + 2) * 2) + 2);
  *(uint *)(param_2 + 0xc4) = uVar6;
  iVar2 = func_0x80004cfc(*(undefined2 *)(&UNK_80126c80 + (uVar5 + 7) * 2),uVar6,0,&DAT_800b867c);
  FUN_800824b8(*(undefined4 *)(param_2 + 0xc4));
  uVar3 = FUN_80031b80(param_2 + 0x78,uVar6 + iVar2);
  FUN_80087868(param_2 + 0x78,uVar1);
  if ((((param_1 == 0x1c) || (param_1 == 0x1f)) || (param_1 == 0x1e)) ||
     (((param_1 == 0x21 || (param_1 == 0x22)) || (param_1 == 0x24)))) {
    DAT_800eb290 = 0xfffffffe;
  }
  if (param_1 == 0x4a) {
    iVar2 = FUN_8008769c(uVar3,param_2 + 0xb8,param_2 + 0xbc,uVar1,param_2 + 0x78);
  }
  else {
    iVar2 = FUN_800874d4(uVar3,param_2 + 0xb8,param_2 + 0xbc,uVar1,param_2 + 0x78);
  }
  uVar6 = iVar2 + 7U & 0xfffffff8;
  *(undefined4 *)(param_2 + 0xdc) = 0xffffffff;
  *(uint *)(param_2 + 0x218) = uVar6;
  iVar2 = func_0x80005e84(*(undefined2 *)(&UNK_80126c80 + (uVar5 + 1) * 2),uVar6);
  uVar6 = iVar2 + 7U & 0xfffffff8;
  *(uint *)(param_2 + 0x1a4) = uVar6;
  iVar2 = func_0x80005ee8(*(undefined2 *)(&UNK_80126c80 + (uVar5 + 2) * 2),uVar6);
  uVar6 = iVar2 + 7U & 0xfffffff8;
  *(uint *)(param_2 + 0x220) = uVar6;
  iVar2 = func_0x80005e84(*(undefined2 *)(&UNK_80126c80 + (uVar5 + 3) * 2),uVar6);
  uVar6 = iVar2 + 7U & 0xfffffff8;
  *(uint *)(param_2 + 0x21c) = uVar6;
  iVar2 = func_0x80005ee8(*(undefined2 *)(&UNK_80126c80 + (uVar5 + 4) * 2),uVar6);
  uVar6 = iVar2 + 7U & 0xfffffff8;
  *(uint *)(param_2 + 0x228) = uVar6;
  iVar2 = func_0x80005e84(*(undefined2 *)(&UNK_80126c80 + (uVar5 + 5) * 2),uVar6);
  uVar6 = iVar2 + 7U & 0xfffffff8;
  *(uint *)(param_2 + 0x224) = uVar6;
  iVar2 = func_0x80005ee8(*(undefined2 *)(&UNK_80126c80 + (uVar5 + 6) * 2),uVar6);
  uVar7 = iVar2 + 7U & 0xfffffff8;
  uVar6 = 0;
  uVar5 = 0;
  do {
    if (*(char *)(param_2 + 8) == (&DAT_800eb1d8)[uVar5]) break;
    uVar6 = uVar6 + 1;
    uVar5 = uVar6 & 0xffff;
  } while ((&DAT_800eb1d8)[uVar6 & 0xffff] != -1);
  if ((&DAT_800eb1d8)[uVar6 & 0xffff] == -1) {
    *(undefined4 *)(param_2 + 600) = 0;
  }
  else {
    *(uint *)(param_2 + 600) = uVar7;
    iVar2 = func_0x80004ec4((&DAT_800eb1e8)[uVar6 & 0xffff],uVar7,0,"SABUN");
    uVar7 = uVar7 + iVar2 + 7 & 0xfffffff8;
  }
  return uVar7;
}
