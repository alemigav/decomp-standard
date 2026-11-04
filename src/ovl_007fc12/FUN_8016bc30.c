/* FUN_8016bc30
 * image   ovl_007fc12 (ovl), base 0x80161cf0
 * address 0x8016bc30  body 0x8016bc30..0x8016c0b3  size 1156 B
 * body sha256 10bb863047835d3912028fd6fe05979ebd0faf1fc5c1448c3ac65357df4d880f
 * provider record sha256 11c9f24bf8fe6dc55e2d751305116fae4fcc9cdc64898324963d1444bf6041a8
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8016bc30(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  short sVar1;
  uint uVar2;
  byte bVar3;
  char cVar4;
  int *piVar5;
  int iVar6;
  ushort uVar7;
  uint uVar8;
  
  uVar8 = param_1[0x82];
  switch(*(undefined1 *)((int)param_1 + 5)) {
  case 0:
    param_1[0x7a] = 0x17000700;
    *(byte *)(param_1 + 0x97) = *(byte *)(param_1 + 0x97) | 1;
    if ((*(ushort *)((int)param_1 + 0x2b6) & 4) != 0) {
      param_1[0x7a] = 0x16000700;
    }
    *(undefined2 *)((int)param_1 + 0x1f2) = 0xffff;
    *(undefined1 *)((int)param_1 + 5) = 1;
    *param_1 = *param_1 | 2;
    func_0x800341dc(uVar8,_DAT_800c76b0);
    *(undefined1 *)((int)param_1 + 0x206) = 0x78;
    *(undefined2 *)(param_1 + 0x7d) = 0x28;
    *(undefined1 *)(param_1 + 0xb5) = 0;
    *(undefined2 *)(param_1 + 0x78) = 0;
    func_0x80035b84(param_1);
    *(uint *)(param_1[0x8d] + 0x468) = *(uint *)(param_1[0x8d] + 0x468) | 0x8000;
    *(uint *)(param_1[0x8d] + 0x5e0) = *(uint *)(param_1[0x8d] + 0x5e0) | 0x8000;
    *(uint *)(param_1[0x8d] + 0x8d0) = *(uint *)(param_1[0x8d] + 0x8d0) | 0x8000;
    *(uint *)(param_1[0x8d] + 0xa48) = *(uint *)(param_1[0x8d] + 0xa48) | 0x8000;
    *(uint *)(param_1[0x8d] + 0xbc0) = *(uint *)(param_1[0x8d] + 0xbc0) | 0x8000;
    uVar2 = func_0x80033604();
    if ((uVar2 & 0xff) % 3 != 0) {
      *(undefined1 *)((int)param_1 + 5) = 8;
      return;
    }
    *(undefined2 *)((int)param_1 + 0x1f6) = 0;
  case 1:
    if (*(char *)((int)param_1 + 0x206) != '\0') {
      *(char *)((int)param_1 + 0x206) = *(char *)((int)param_1 + 0x206) + -1;
      *(short *)(uVar8 + 4) = *(short *)(uVar8 + 4) + 5;
      *(short *)(uVar8 + 6) = *(short *)(uVar8 + 6) + 5;
    }
  case 5:
  case 10:
switchD_8016bc78_caseD_5:
    cVar4 = func_0x80089d54(param_1,param_2,param_3,0x200);
    *(char *)((int)param_1 + 5) = *(char *)((int)param_1 + 5) + cVar4;
    break;
  case 2:
    bVar3 = func_0x80033604();
    *(byte *)((int)param_1 + 0x207) = (bVar3 & 0xf) + 1;
    sVar1 = *(short *)(param_1 + 0x7d);
    *(undefined1 *)((int)param_1 + 5) = 3;
    *(short *)(param_1 + 0x7d) = sVar1 + -1;
    if ((short)(sVar1 + -1) != -1) goto switchD_8016bc78_caseD_3;
    *(undefined1 *)((int)param_1 + 5) = 4;
    *(undefined2 *)(param_1 + 0x7d) = 0x1e;
    break;
  case 3:
switchD_8016bc78_caseD_3:
    if (*(char *)((int)param_1 + 0x206) != '\0') {
      *(char *)((int)param_1 + 0x206) = *(char *)((int)param_1 + 0x206) + -1;
      *(short *)(uVar8 + 4) = *(short *)(uVar8 + 4) + 5;
      *(short *)(uVar8 + 6) = *(short *)(uVar8 + 6) + 5;
    }
    cVar4 = *(char *)((int)param_1 + 0x207) + -1;
    *(char *)((int)param_1 + 0x207) = cVar4;
    if (cVar4 == -1) {
      *(undefined1 *)((int)param_1 + 5) = 1;
    }
    break;
  case 4:
    cVar4 = *(char *)((int)param_1 + 0x207) + -1;
    *(char *)((int)param_1 + 0x207) = cVar4;
    if (cVar4 == -1) {
      *(undefined1 *)((int)param_1 + 5) = 5;
    }
    break;
  case 6:
    bVar3 = func_0x80033604();
    *(byte *)((int)param_1 + 0x207) = (bVar3 & 0x3f) + 0x3c;
    sVar1 = *(short *)(param_1 + 0x7d);
    *(undefined1 *)((int)param_1 + 5) = 4;
    *(short *)(param_1 + 0x7d) = sVar1 + -1;
    if ((short)(sVar1 + -1) == -1) {
      *(undefined1 *)((int)param_1 + 5) = 7;
      *(uint *)(param_1[0x8d] + 0x468) = *(uint *)(param_1[0x8d] + 0x468) | 0x8000;
      *(uint *)(param_1[0x8d] + 0x5e0) = *(uint *)(param_1[0x8d] + 0x5e0) | 0x8000;
      *(uint *)(param_1[0x8d] + 0x8d0) = *(uint *)(param_1[0x8d] + 0x8d0) | 0x8000;
      *(uint *)(param_1[0x8d] + 0xa48) = *(uint *)(param_1[0x8d] + 0xa48) | 0x8000;
      *(uint *)(param_1[0x8d] + 0xbc0) = *(uint *)(param_1[0x8d] + 0xbc0) | 0x8000;
    }
    break;
  case 8:
    if (*(char *)((int)param_1 + 0x206) != '\0') {
      *(char *)((int)param_1 + 0x206) = *(char *)((int)param_1 + 0x206) + -1;
      *(short *)(uVar8 + 4) = *(short *)(uVar8 + 4) + 5;
      *(short *)(uVar8 + 6) = *(short *)(uVar8 + 6) + 5;
      if (*(char *)((int)param_1 + 0x206) != '\0') break;
    }
    *(undefined1 *)((int)param_1 + 5) = 7;
    break;
  case 9:
    param_1[0x7a] = 0x7000700;
    if ((*(ushort *)((int)param_1 + 0x2b6) & 4) != 0) {
      param_1[0x7a] = 0x16000700;
    }
    *(undefined1 *)((int)param_1 + 5) = 10;
    goto switchD_8016bc78_caseD_5;
  case 0xb:
    *(undefined1 *)((int)param_1 + 5) = 0;
  }
  uVar7 = *(short *)((int)param_1 + 0x1f6) + 1;
  *(ushort *)((int)param_1 + 0x1f6) = uVar7;
  if ((*(ushort *)((int)param_1 + 0x1aa) & 0x80) != 0) {
    iVar6 = 0xf;
    if ((*(char *)(param_1[0x8d] + 99) != '\x10') && ((uVar7 & 3) == 0)) {
      piVar5 = (int *)(param_1[0x8d] + 0x60);
      do {
        iVar6 = iVar6 + -1;
        *piVar5 = *piVar5 + -0x10101;
        piVar5 = piVar5 + 0x5e;
      } while (iVar6 != 0);
    }
  }
  if (*(short *)(param_1 + 0x6a) == 0) {
    return;
  }
  if ((*(byte *)(param_1 + 0xb5) & 0x80) == 0) {
    uVar8 = param_1[0xb];
    param_1[0xb] = uVar8 - 5;
    if ((int)((int)*(short *)(param_1 + 0x6a) + 300U) <= (int)(uVar8 - 5)) goto LAB_8016c08c;
    param_1[0xb] = (int)*(short *)(param_1 + 0x6a) + 300U;
  }
  else {
    if (*(byte *)(param_1 + 0xb5) < 0xa0) {
      param_1[0xb] = param_1[0xb] - 2;
      goto LAB_8016c08c;
    }
    param_1[0xb] = param_1[0xb] + 2;
    if (*(char *)(param_1 + 0xb5) != -0x41) goto LAB_8016c08c;
  }
  *(undefined1 *)(param_1 + 0xb5) = 0x80;
LAB_8016c08c:
  *(char *)(param_1 + 0xb5) = *(char *)(param_1 + 0xb5) + '\x01';
  return;
}
